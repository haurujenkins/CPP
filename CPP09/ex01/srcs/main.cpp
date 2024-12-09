/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:33:52 by lle-pier          #+#    #+#             */
/*   Updated: 2024/12/09 11:02:29 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Arg format: Just one string needed" << std::endl;
        return (1);
    }
    try {
        std::cout << RPN::evaluate(argv[1]) << std::endl;
    }catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}