/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:56 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/14 16:24:59 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(std::string name, unsigned int attackDamage, unsigned int hitpoints, unsigned int energyPoints);
        ClapTrap(ClapTrap const & src);
        ClapTrap & operator=(ClapTrap const & src);
        ~ClapTrap();

        virtual void attack(const std::string & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        unsigned int getDamage() const;
        
    protected:
        std::string name;
        unsigned int hitpoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
};

#endif