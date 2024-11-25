/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:08 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/25 17:22:21 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Span.hpp"

int main(void)
{

    std::cout << "try with addNumber : " << std::endl;
    
    try
    {
        Span sp(100);

        for (int i = 0; i < 100; i++)
        {
            sp.addNumber(i*2);
        }
        sp.printNumbers();
        std::cout << "longest span : " << sp.longestSpan() << std::endl;
        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\ntry with addRange : " << std::endl;
    
    try
    {
        Span sp(10);

        int arr[] = {5, 10, 15, 20, 25, 30, 35};
        std::vector<int> moreNumbers(arr, arr + sizeof(arr) / sizeof(int));
        sp.addRange(moreNumbers.begin(), moreNumbers.end());
        sp.printNumbers();
        std::cout << "longest span : " << sp.longestSpan() << std::endl;
        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}