/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:59:19 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/19 16:38:24 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

void toFloat(const std::string str)
{
    std::cout << "type : " << "float" << std::endl;
    
    if (str == "-inff" || str == "+inff" || str == "nanf")
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
    
    char charValue = static_cast<char>(d);
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

bool is_float(const std::string& str)
{
    if (str[0] == '\0') return false;

    if (caseInsensitiveCompare(str, "-inff") ||
        caseInsensitiveCompare(str, "+inff") ||
        caseInsensitiveCompare(str, "nanf"))
        return true;

    size_t len = ft_strlen(str);
    bool endsWithF = (str[len - 1] == 'f' || str[len - 1] == 'F');

    size_t numberLength = endsWithF ? len - 1 : len;

    bool hasDecimalPoint = false;
    bool hasExponent = false;
    bool hasDigits = false;

    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    for (size_t i = start; i < numberLength; ++i)
    {
        char c = str[i];

        if (c == '.')
        {
            if (hasDecimalPoint || hasExponent) return false;
            hasDecimalPoint = true;
        }
        else if (c == 'e' || c == 'E')
        {
            if (hasExponent || !hasDigits) return false;
            hasExponent = true;
            hasDigits = false;

            if (i + 1 < numberLength && (str[i + 1] == '-' || str[i + 1] == '+'))
                ++i;
        }
        else if (my_isdigit(c))
            hasDigits = true;
        else
            return false;
    }
    
    return hasDigits;
}