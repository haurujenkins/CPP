/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:51:47 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 16:56:45 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}
Weapon::~Weapon(){}

std::string const &Weapon::getType() const
{
	return (this->_type);
}

void Weapon::setType(std::string type){
	this->_type = type;
}