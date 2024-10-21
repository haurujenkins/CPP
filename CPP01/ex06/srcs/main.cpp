/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:38:47 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 17:35:34 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char **argv) {

    if (argc != 2)
        return (std::cerr << "bad number of args" << std::endl, 0);
    Harl harl;

    harl.complain(argv[1]);

    return 0;
}