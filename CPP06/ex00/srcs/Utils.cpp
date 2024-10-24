/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:52:39 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/24 16:17:22 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Main.hpp"

void to_char(const std::string str)
{
    const char c = str[1];
    
    int intValue = static_cast<int>(c);
    float floatValue = static_cast<int>(c);
    double doubleValue = static_cast<double>(c);

    std::cout << "char : " << c << std::endl;
    std::cout << "int : " << intValue << std::endl;
    std::cout << "float : " << floatValue << std::endl;
    std::cout << "double : " << doubleValue << std::endl;
}


void to_int(const std::string str)
{
    int i = stringToInt(str);
    
    char charValue = static_cast<char>(i);
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

int stringToInt(const std::string& str) {
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

bool is_float(const std::string str)
{
    if (str[0] == '\0') return false;
    std::size_t i = 0;
    bool pointSeen = false;
    std::size_t len = ft_strlen(str);

    if (str[0] == '-' || str[0] == '+')
        i++;

    while (str[i])
    {
        if (str[i] == '.')
        {
            if (pointSeen)
                return false;
            pointSeen = true;
        } else if (!my_isdigit(str[i]))
        {
            if (i == len -1 && (str[i] == 'f' || str[i] == 'F'))
                return true;
            return false;
        }
        i++;
    }
    return pointSeen;
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