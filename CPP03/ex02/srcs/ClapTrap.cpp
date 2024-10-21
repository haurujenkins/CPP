/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:54 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/14 16:39:57 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("NoName"), hitpoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is created" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int attackDamage, unsigned int hitpoints, unsigned int energyPoints)
{
    this->name = name;
    this->hitpoints = hitpoints;
    this->energyPoints = energyPoints;
    this->attackDamage = attackDamage;
    std::cout << "ClapTrap " << name << " is created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
    std::cout << "ClapTrap " << name << " is created by copy" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
    std::cout << "ClapTrap " << name << " is affected. New name : " << src.name << std::endl;
    if (this != &src)
    {
        this->name = src.name;
        this->hitpoints = src.hitpoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints < 1)
    {
        std::cout << name << " can't attack, not enough energy!\n" << std::endl;
        return;
    }
    if (hitpoints < 1)
    {
        std::cout << name << " can't attack, it's dead!\n" << std::endl;
        return;
    }
    energyPoints -= 1;
    std::cout << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitpoints < 1)
    {
        std::cout << name << " can't take damage, it's dead!\n" << std::endl;
        return;
    }
    if (hitpoints < amount || hitpoints - amount < 1)
    {
        hitpoints = 0;
        std::cout << name << " is dead!\n" << std::endl;
        return;
    }
    hitpoints -= amount;
    std::cout << name << " take " << amount << " points of damage!\nHe has " << hitpoints << " hitpoints left!\n" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount + hitpoints > 100)
    {
        std::cout << name << " can't be repaired, more than 100 hitpoints!\n" << std::endl;
        return;
    }
    if (energyPoints < 1)
    {
        std::cout << name << " can't be repaired, not enough energy!\n" << std::endl;
        return;
    }
    if (hitpoints < 1)
    {
        std::cout << name << " can't be repaired, it's dead!\n" << std::endl;
        return;
    }
    hitpoints += amount;
    energyPoints -= amount;
    std::cout << name << " is repaired by " << amount << " points!\nHe has " << hitpoints << " hitpoints left!\n" << std::endl;
}

unsigned int ClapTrap::getDamage() const
{
    return attackDamage;
}