/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:08 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/25 15:00:14 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <vector>

int main( void )
{
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);

    try 
    {
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Ellement found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Element found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}