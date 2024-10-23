/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:26 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/23 16:01:06 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    public:
        static void convert(const std::string str);
};

class ImpossibleConversion : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Impossible conversion";
        }
};

#endif