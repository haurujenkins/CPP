/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:49:14 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 19:25:21 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}

void HumanB::attack() const{
	if (_weapon)
		std::cout << this->_name << " attacks with their " \
		<< this->_weapon->getType() << std::endl;
	else
		std::cout << "attacks with nothing..." << std::endl;
}