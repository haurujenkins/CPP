/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:59:19 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/18 17:00:36 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

void toFloat(const std::string str)
{
    std::cout << "str : " << "float" << std::endl;
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        std::cout << "char : " << "Non displayable" << std::endl;
        float f = strtof(str.c_str(), NULL);
        std::cout << "float : " << f << std::endl;
        double d = strtod(str.c_str(), NULL);
        std::cout << "double : " << d << std::endl;
        std::cout << "int : " << "impossible" << std::endl;
        return;
    }

    float f = strtof(str.c_str(), NULL);
    
    char charValue = static_cast<char>(f + 0);
    double doubleValue = static_cast<double>(f);
    int intValue = static_cast<int>(f);

    if (charValue < 32 || charValue > 126)
        std::cout << "char : " << "Non displayable" << std::endl;
    else
        std::cout << "char : " << charValue << std::endl;
    std::cout << "double : " << f << std::endl;
    std::cout << "float : " << doubleValue << std::endl;
    std::cout << "int : " << intValue << std::endl;
}

bool is_float(const std::string& str)
{
    if (str[0] == '\0') return false;

    if (caseInsensitiveCompare(str, "-inff") ||
        caseInsensitiveCompare(str, "+inff") ||
        caseInsensitiveCompare(str, "nanf")) {
        return true;
    }

    size_t len = ft_strlen(str);
    bool endsWithF = (str[len - 1] == 'f' || str[len - 1] == 'F');

    size_t numberLength = endsWithF ? len - 1 : len;

    bool hasDecimalPoint = false;
    bool hasExponent = false;
    bool hasDigits = false;

    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    for (size_t i = start; i < numberLength; ++i) {
        char c = str[i];

        if (c == '.') {
            if (hasDecimalPoint || hasExponent) return false;
            hasDecimalPoint = true;
        }
        else if (c == 'e' || c == 'E') {
            if (hasExponent || !hasDigits) return false;
            hasExponent = true;
            hasDigits = false;

            if (i + 1 < numberLength && (str[i + 1] == '-' || str[i + 1] == '+')) {
                ++i;
            }
        }
        else if (my_isdigit(c)) {
            hasDigits = true;
        }
        else {
            return false;
        }
    }

    return hasDigits;
}