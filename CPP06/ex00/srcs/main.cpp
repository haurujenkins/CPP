/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:36 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/24 14:05:50 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    std::cout << "your entry : " << argv[1] << std::endl;
    if (argc != 2)
    {
        std::cerr << "just one arg please";
        return (0);
    }
    else
        ScalarConverter::convert(argv[1]);
    return (0);
}
