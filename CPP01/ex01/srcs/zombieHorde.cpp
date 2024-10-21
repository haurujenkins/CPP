/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:21:06 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 19:34:48 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    std::ostringstream oss;
    
    for (int i = 0; i < N; i++) {
        oss.str("");
        oss << i; 
        horde[i] = Zombie(name + oss.str()); 
    }
    return horde;
}
