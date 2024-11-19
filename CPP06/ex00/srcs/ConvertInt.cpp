/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertInt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:20 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/19 16:38:27 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

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

void toInt(const std::string str)
{
    std::cout << "type : " << "int" << std::endl;
    
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
    if (d >= -FLT_MAX && d <= FLT_MAX && !isScientificNotation(d))
        std::cout << "float : " << floatValue << ".0f" << std::endl;
    else if (d >= -FLT_MAX && d <= FLT_MAX)
        std::cout << "float : " << floatValue << "f" << std::endl;
    else
        std::cout << "float : " << "impossible" << std::endl;
    
    //double
    if (d >= -DBL_MAX && d <= DBL_MAX && !isScientificNotation(d))
        std::cout << "double : " << d << ".0" << std::endl;
    else if (d >= -DBL_MAX && d <= DBL_MAX)
        std::cout << "double : " << d << std::endl;
    else
        std::cout << "double : " << "impossible" << std::endl;
}