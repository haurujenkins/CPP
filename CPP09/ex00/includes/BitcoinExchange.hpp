/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:30:02 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/28 16:10:30 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    public:
        static void convFromArg(int argc, char *argv[]);
        static float getValueAtDate(const std::string& date);
        static void convFromFile(std::ifstream& file);

    private:
        BitcoinExchange() {};
};

#endif