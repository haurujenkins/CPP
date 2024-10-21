/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:14:46 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 16:25:00 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{
public :
	HumanB(const std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack() const;

private :
	std::string _name;
	Weapon *_weapon;
};

#endif