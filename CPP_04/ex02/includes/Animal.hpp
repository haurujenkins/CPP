/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:56 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/16 13:31:18 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(Animal const & animal);
        Animal & operator=(Animal const & animal);
        virtual void makeSound() const = 0;
        std::string getType() const;
        virtual void setIdea(int index, std::string idea) = 0;
        virtual std::string getIdea(int index) const = 0;
};

#endif