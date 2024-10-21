/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:53:15 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/14 16:41:50 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("NoName", 100, 50, 20)
{
    std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " is destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    if (hitpoints < 1 || energyPoints < 1)
    {
        std::cout << "ScavTrap " << name << " can't guard the gate, it's dead!\n" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode\n" << std::endl;
}

void ScavTrap::attack(const std::string & target)
{
    if (hitpoints < 1)
    {
        std::cout << "ScavTrap " << name << " can't attack, it's dead!\n" << std::endl;
        return;
    }
    if (energyPoints > 0) 
    {
        std::cout << "OMG !!! ScavTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "ScavTrap " << name << " n'a plus d'énergie pour attaquer !" << std::endl;
}