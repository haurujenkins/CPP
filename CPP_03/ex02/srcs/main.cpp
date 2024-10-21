/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:26 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/14 16:37:27 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main()
{
    ClapTrap Naruto("Naruto", 10, 30, 30);
    ScavTrap Sasuke("Sasuke");
    FragTrap Sakura("Sakura");
    std::cout << std::endl;
    Naruto.attack("Sasuke");
    Sasuke.takeDamage(Naruto.getDamage());

    Sasuke.attack("Naruto");
    Naruto.takeDamage(Sasuke.getDamage());

    Sakura.attack("Sasuke");
    Sasuke.takeDamage(Sakura.getDamage());
    
    Naruto.beRepaired(10);
    Sasuke.beRepaired(10);
    Sakura.beRepaired(10);

    Sasuke.guardGate();
    Sakura.highFivesGuys();
    return 0;
}