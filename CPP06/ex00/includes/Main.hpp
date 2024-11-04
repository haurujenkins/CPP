/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:53:35 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/04 15:02:06 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include "./ScalarConverter.hpp"

void toChar(const std::string str);
void toInt(const std::string str);
void toDouble(const std::string str);
void toFloat(const std::string str);
bool my_isdigit(char c);
int stringToInt(const std::string& str);
bool is_int(const std::string str);
bool is_float(const std::string& str);
bool is_double(const std::string str);
bool is_char(const std::string str);

#endif