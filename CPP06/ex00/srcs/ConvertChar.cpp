/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertChar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:58:02 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/19 16:38:39 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

void toChar(const std::string str)
{
    std::cout << "type : " << "char" << std::endl;
    
    const char c = str[1];
    
    int intValue = static_cast<int>(c);
    float floatValue = static_cast<float>(c);
    double doubleValue = static_cast<double>(c);

    std::cout << "char : '" << c << "'" << std::endl;
    std::cout << "int : " << intValue << std::endl;
    std::cout << "float : " << floatValue << ".0f" << std::endl;
    std::cout << "double : " << doubleValue << ".0" << std::endl;
}

bool is_char(const std::string str)
{
    return (ft_strlen(str) == 3 && str[0] == '\'' && str[2] == '\'');
}