/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:29:24 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/28 16:20:17 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    std::cout << "test from argc argv :\n" << std::endl;
    BitcoinExchange::convFromArg(argc, argv);
    
    std::cout << "\ntest from file adress :\n" << std::endl;
    std::ifstream file("myTest.txt");
    BitcoinExchange::convFromFile(file);
    
    std::cout << "\ntest from string :\n" << std::endl;
    std::string date = "2024-02-28";
    std::cout << "2024-02-28 => 1 = " << BitcoinExchange::getValueAtDate(date);
    return 0;
}