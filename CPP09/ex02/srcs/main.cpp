/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:52:11 by lle-pier          #+#    #+#             */
/*   Updated: 2024/12/09 17:19:49 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        std::cerr << "Error: need integers to work" << std::endl;
        return 0;
    }

    try{
        PmergeMe::sortList(argc, argv);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
            
    return (0);
}