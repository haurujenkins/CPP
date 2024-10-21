/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:32:06 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/15 21:47:55 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(Dog const & dog);
        Dog & operator=(Dog const & dog);
        void makeSound() const;
        void setIdea(int index, std::string idea);
        std::string getIdea(int index) const;
    private:
        Brain* brain;
};

#endif