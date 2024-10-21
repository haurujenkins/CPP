/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:17:38 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 19:27:43 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

int main()
{
	{
		Weapon knife = Weapon("knife");
		HumanA felix("Felix", knife);
		felix.attack();
		knife.setType("hands");
		felix.attack();
	}
	{
		Weapon gun = Weapon("assault rifle");
		HumanB mike("Mike");
		mike.setWeapon(gun);
		mike.attack();
		gun.setType("sniper");
		mike.attack();
	}
	return 0;
}