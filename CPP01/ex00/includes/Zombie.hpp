/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:13:58 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/16 17:05:18 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);

private:
	std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif