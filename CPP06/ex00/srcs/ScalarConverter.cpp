/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:33 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/24 15:45:10 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void convert(const std::string str)
{
    if (is_int(str))
        std::cout << "int" << std::endl;
    else if (is_double(str))
        std::cout << "double" << std::endl;
    else if (is_float(str))
        std::cout << "float" << std::endl;
    else if (is_char(str))
        to_char(str);
}

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

bool my_isdigit(char c) {
    return c >= '0' && c <= '9';
}

int ft_strlen(const std::string str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
    
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
    int i = 0;
    bool pointSeen = false;
    int len = ft_strlen(str);

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
    int i = 0, len = ft_strlen(str);
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