/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:33 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/24 16:09:15 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

void ScalarConverter::convert(const std::string str)
{
    if (is_int(str))
        to_int(str);
    else if (is_double(str))
        std::cout << "double" << std::endl;
    else if (is_float(str))
        std::cout << "float" << std::endl;
    else if (is_char(str))
        to_char(str);
}
