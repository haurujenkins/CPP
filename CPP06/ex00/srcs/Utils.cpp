/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:52:39 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/04 15:10:39 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Main.hpp"

#include <string>
#include <iostream>
#include <cmath>

float stringToFloat(const std::string& str)
{
    float result = 0.0f;
    float decimalDivisor = 10.0f;
    bool isNegative = (str[0] == '-');
    size_t i = (isNegative || str[0] == '+') ? 1 : 0;
    bool decimalPointEncountered = false;

    for (; i < str.length(); ++i) {
        char c = str[i];

        if (c == '.') {
            decimalPointEncountered = true;
            continue;
        }

        int digit = c - '0';

        if (!decimalPointEncountered) {
            result = result * 10 + digit;
        } else {
            result += digit / decimalDivisor;
            decimalDivisor *= 10.0f;
        }
    }

    if (isNegative) {
        result = -result;
    }

    return result;
}

double stringToDouble(const std::string& str)
{
    double result = 0.0;
    double decimalDivisor = 10.0;
    bool isNegative = (str[0] == '-');
    size_t i = (isNegative || str[0] == '+') ? 1 : 0;
    bool decimalPointEncountered = false;

    for (; i < str.length(); ++i) {
        char c = str[i];

        if (c == '.') {
            decimalPointEncountered = true;
            continue;
        }

        int digit = c - '0';

        if (!decimalPointEncountered) {
            result = result * 10 + digit;
        } else {
            result += digit / decimalDivisor;
            decimalDivisor *= 10.0;
        }
    }

    if (isNegative) {
        result = -result;
    }
    return result;
}

void toDouble(const std::string str)
{
    std::cout << "str : " << "double" << std::endl;
    double d = stringToDouble(str);
    
    char charValue = static_cast<char>(d + 0);
    float floatValue = static_cast<float>(d);
    int intValue = static_cast<int>(d);

    std::cout << "char : " << charValue << std::endl;
    std::cout << "double : " << d << std::endl;
    std::cout << "float : " << floatValue << std::endl;
    std::cout << "int : " << intValue << std::endl;
}

void toFloat(const std::string str)
{
    std::cout << "str : " << "float" << std::endl;
    float f = stringToDouble(str);
    
    char charValue = static_cast<char>(f + 0);
    double doubleValue = static_cast<double>(f);
    int intValue = static_cast<int>(f);

    std::cout << "char : " << charValue << std::endl;
    std::cout << "double : " << f << std::endl;
    std::cout << "float : " << doubleValue << std::endl;
    std::cout << "int : " << intValue << std::endl;
}

void toChar(const std::string str)
{
    std::cout << "str : " << "char" << std::endl;
    const char c = str[1];
    
    int intValue = static_cast<int>(c);
    float floatValue = static_cast<float>(c);
    double doubleValue = static_cast<double>(c);

    std::cout << "char : " << c << std::endl;
    std::cout << "int : " << intValue << std::endl;
    std::cout << "float : " << floatValue << std::endl;
    std::cout << "double : " << doubleValue << std::endl;
}


void toInt(const std::string str)
{
    std::cout << "str : " << "int" << std::endl;
    int i = stringToInt(str);
    
    char charValue = static_cast<char>(i + 0);
    float floatValue = static_cast<float>(i);
    double doubleValue = static_cast<double>(i);

    std::cout << "char : " << charValue << std::endl;
    std::cout << "int : " << i << std::endl;
    std::cout << "float : " << floatValue << std::endl;
    std::cout << "double : " << doubleValue << std::endl;
}

bool my_isdigit(char c) {
    return c >= '0' && c <= '9';
}

std::size_t ft_strlen(const std::string str)
{
    std::size_t i = 0;

    while (str[i])
        i++;
    return i;
    
}

int stringToInt(const std::string& str)
{
    int result = 0, sign = 1;
    std::size_t i = 0, len = ft_strlen(str);

    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    for (; i < len; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            std::cerr << "Erreur : caractère non numérique trouvé !" << std::endl;
            return 0;
        }
    }

    return result * sign;
}

bool is_int(const std::string str)
{
    if (str[0] == '\0') return false;
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;

    while (str[i])
    {
        if (!my_isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool is_float(const std::string& str)
{
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

bool is_double(const std::string str)
{
    if (str[0] == '\0') return false;
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

bool is_char(const std::string str)
{
    return (ft_strlen(str) == 3 && str[0] == '\'' && str[2] == '\'');
}