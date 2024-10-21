/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:50:11 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 16:57:45 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : _name(name), _weapon(&weapon) {}

HumanA::~HumanA(){}

void HumanA::attack() const{
	std::cout << this->_name << " attacks with their " \
	<< this->_weapon->getType() << std::endl;
}