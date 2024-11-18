/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertChar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:58:02 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/18 17:30:26 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

void toChar(const std::string str)
{
    std::cout << "str : " << "char" << std::endl;
    const char c = str[1];
    
    int intValue = static_cast<int>(c);
    float floatValue = static_cast<float>(c);
    double doubleValue = static_cast<double>(c);

    std::cout << "char : " << c << std::endl;
    std::cout << "int : " << intValue << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float : " << floatValue << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double : " << doubleValue << std::endl;
}

bool is_char(const std::string str)
{
    return (ft_strlen(str) == 3 && str[0] == '\'' && str[2] == '\'');
}