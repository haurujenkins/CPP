/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:14:01 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 19:34:23 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main() {
    Zombie* myZombie = newZombie("Foo Heap");
    myZombie->announce();

    delete myZombie;

    randomChump("Bar Stack");

    return 0;
}