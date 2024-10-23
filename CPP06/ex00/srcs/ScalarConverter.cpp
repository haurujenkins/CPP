/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:33 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/23 16:02:11 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string str)
{
    try
    {
        int i = std::stoi(str);
        std::cout << "char: ";
        if (i < 32 || i > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "char: impossible" << std::endl;
        std::cerr << "int: impossible" << std::endl;
        std::cerr << "float: impossible" << std::endl;
        std::cerr << "double: impossible" << std::endl;
    }
}