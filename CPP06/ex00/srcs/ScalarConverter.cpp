/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:33 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/04 14:09:53 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

void ScalarConverter::convert(const std::string str)
{
    if (is_int(str))
        toInt(str);
    else if (is_double(str))
        toDouble(str);
    else if (is_float(str))
        toFloat(str);
    else if (is_char(str))
        toChar(str);
    else
        std::cout << "non printable" << std::endl; 
}
