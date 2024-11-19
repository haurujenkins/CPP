/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:42 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/19 16:38:34 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

void toDouble(const std::string str)
{
    std::cout << "type : " << "double" << std::endl;
    
    if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "char : " << "impossibe" << std::endl;
        std::cout << "int : " << "impossible" << std::endl;
        double d = strtod(&str[0], NULL);
        float f = static_cast<float>(d);
        std::cout << std::fixed << std::setprecision(1) << "float : " << f << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double : " << d << std::endl;
        return;
    }
    double d = strtod(&str[0], NULL);
    
    char charValue = static_cast<char>(d + 0);
    float floatValue = static_cast<float>(d);
    int intValue = static_cast<int>(d);

    //char
    if ((d < 32 && d >= 0) || (d > 126 && d <= 127))
        std::cout << "char : " << "Non displayable" << std::endl;
    else if (d < 0 || d > 127)
        std::cout << "char : " << "impossible" << std::endl;
    else
        std::cout << "char : " << "'" << charValue << "'" << std::endl;
    
    //int
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << "int : " << intValue << std::endl;
    else
        std::cout << "int : " << "impossible" << std::endl;

    //float
    if (d >= -FLT_MAX && d <= FLT_MAX && !isScientificNotation(d) && isInteger(d))
        std::cout << "float : " << floatValue << ".0f" << std::endl;
    else if (d >= -FLT_MAX && d <= FLT_MAX)
        std::cout << "float : " << floatValue << "f" << std::endl;
    else
        std::cout << "float : " << "impossible" << std::endl;
    
    //double
    if (d >= -DBL_MAX && d <= DBL_MAX && !isScientificNotation(d) && isInteger(d))
        std::cout << "double : " << d << ".0" << std::endl;
    else if (d >= -DBL_MAX && d <= DBL_MAX)
        std::cout << "double : " << d << std::endl;
    else
        std::cout << "double : " << "impossible" << std::endl;
}

bool is_double(const std::string str)
{
    if (str[0] == '\0') return false;

    if (caseInsensitiveCompare(str, "-inf") ||
        caseInsensitiveCompare(str, "+inf") ||
        caseInsensitiveCompare(str, "nan")) {
        return true;
    }

    std::size_t i = 0, len = ft_strlen(str);
    bool pointSeen = false, eSeen = false;

    if (str[0] == '-' || str[0] == '+')
        i++;

    while (str[i])
    {
        if (str[i] == '.')
        {
            if (pointSeen || eSeen)
                return false;
            pointSeen = true;
        } else if (str[i] == 'e' || str[i] == 'E')
        {
            if (eSeen || i == len - 1)
                return false;
            eSeen = true;
        } else if (!my_isdigit(str[i]) && !(i > 0 && (str[i] == '+' || str[i] == '-') && (str[i-1] == 'e' || str[i-1] == 'E')))
            return false;
        i++;
    }
    return pointSeen;
}