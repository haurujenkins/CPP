/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:26 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/22 14:17:01 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "./Main.hpp"

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        static void convert(const std::string str);
};

#endif