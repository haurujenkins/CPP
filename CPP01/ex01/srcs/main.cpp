/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:14:01 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/23 17:34:53 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

#include "Zombie.hpp"

int main() {
    int hordeSize = 5;
    std::string hordeName = "Zombie";

    Zombie* horde = zombieHorde(hordeSize, hordeName);

    for (int i = 0; i < hordeSize; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
