/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:36 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/24 16:19:00 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "just one arg please";
        return (0);
    }
    else
        ScalarConverter::convert(argv[1]);
    return (0);
}
