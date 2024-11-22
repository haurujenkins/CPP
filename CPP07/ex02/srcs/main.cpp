/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:08 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/22 17:15:51 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Array.hpp"

int main( void )
{
    try {
        
        Array<int> arr(5);

        for (unsigned int i = 0; i < arr.size(); ++i)
            arr[i] = i * 10;
        
        std::cout << "Array elements:" << std::endl;
        for (unsigned int i = 0; i < arr.size(); ++i)
        {
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        }

        std::cout << "Testing out-of-bounds acces..." << std::endl;
        try 
        {
            std::cout << arr[10] << std::endl;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        Array<int> arr_copy = arr;
        std::cout << "Array copy elements:" << std::endl;
        for (unsigned int i = 0; i < arr_copy.size(); ++i)
            std::cout << "arr_copy[" << i << "] = " << arr_copy[i] << std::endl;
        
        arr[0] = 999;
        std::cout << "\nAfter modifying arr, the copy remains unchanged:" << std::endl;
        std::cout << "arr[0] = " << arr[0] << std::endl;
        std::cout << "arr_copy[0] = " << arr_copy[0] << std::endl;

        Array<int> arr_assigned(3);
        arr_assigned = arr;
        std::cout << "\nAfter assignment from arr to arr_assigned:" << std::endl;
        for (unsigned int i = 0; i < arr_assigned.size(); ++i)
        {
            std::cout << "arr_assigned[" << i << "] = " << arr_assigned[i] << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occured: " << e.what() << std::endl;
    }
    return (0);
}