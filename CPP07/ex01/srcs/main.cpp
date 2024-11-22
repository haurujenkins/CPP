/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:08 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/22 14:44:28 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/iter.hpp"

void ft_strlen(std::string const &str)
{
    std::cout << "str: " << str << ", len: " << str.length() << std::endl;
}

void intPrint(int const &i)
{
    std::cout << "int: " << i << std::endl;
}

int main( void )
{
    std::string str[] = {"Hello", "Guys", "How", "Are", "You"};
    int tab[] = {0, 1, 2, 3, 4};
    
    ::iter(str, 5, ft_strlen);
    ::iter(tab, 5, intPrint);
    return 0;
}