/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:42 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/18 17:02:14 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

void toDouble(const std::string str)
{
    std::cout << "str : " << "double" << std::endl;
    if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "char : " << "Non displayable" << std::endl;
        float f = strtof(str.c_str(), NULL);
        std::cout << "float : " << f << std::endl;
        double d = strtod(str.c_str(), NULL);
        std::cout << "double : " << d << std::endl;
        std::cout << "int : " << "impossible" << std::endl;
        return;
    }
    double d = strtod(str.c_str(), NULL);
    
    char charValue = static_cast<char>(d + 0);
    float floatValue = static_cast<float>(d);
    int intValue = static_cast<int>(d);

    if (charValue < 32 || charValue > 126)
        std::cout << "char : " << "Non displayable" << std::endl;
    else
        std::cout << "char : " << charValue << std::endl;
    std::cout << "double : " << d << std::endl;
    std::cout << "float : " << floatValue << std::endl;
    std::cout << "int : " << intValue << std::endl;
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