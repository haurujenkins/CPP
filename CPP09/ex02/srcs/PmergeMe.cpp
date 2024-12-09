/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:51:57 by lle-pier          #+#    #+#             */
/*   Updated: 2024/12/09 15:31:22 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <unistd.h>

// print list | ok
// afficher les entiers tries | 
// calcul du temps passe | ok

int myAtoi(const char* str)
{
    int result = 0;
    int i = 0;

    if (str[i] == '-')
    {
        throw std::runtime_error("Error: numbers must be positive");
    }
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            throw std::invalid_argument("Error: arg is not a number");
        }
        if (result > (INT_MAX - (str[i] - '0')) / 10)
        {
            throw std::overflow_error("Error: arg is bigger than INT_MAX");
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

void    sortListVector(int argc, char *argv[])
{
    std::vector<int> list;

    for (int i = 1; i < argc; i++)
    {
        int num = myAtoi(argv[i]);
        if (num != 0 || argv[i][0] == '0')
            list.push_back(num);
    }
}

void    sortListList(int argc, char *argv[])
{
    std::list<int> list;
    for (int i = 1; i < argc; i++)
    {
        int num = myAtoi(argv[i]);
        if (num != 0 || argv[i][0] == '0')
            list.push_back(num);
    }
}

void    PmergeMe::sortList(int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
        myAtoi(argv[i]);
    std::cout << "Avant tri : [ ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << "]" << std::endl;
    
    const std::clock_t v_start = std::clock();
    sortListVector(argc, argv);
    const std::clock_t v_end = std::clock();
    double v_time = 1000.0 * (v_end - v_start) / CLOCKS_PER_SEC;
    
    const std::clock_t l_start = std::clock();
    sortListList(argc, argv);
    const std::clock_t l_end = std::clock();
    double l_time = 1000.0 * (l_end - l_start) / CLOCKS_PER_SEC;
    std::cout << "time past [std::vector]: " << v_time << " ms" << std::endl;
    std::cout << "time past [std::list]: " << l_time << " ms" << std::endl;
}