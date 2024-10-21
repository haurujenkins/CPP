/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:38:55 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/15 20:39:09 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const & dog)
{
    *this = dog;
}

Dog & Dog::operator=(Dog const & dog)
{
    this->type = dog.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Wouf" << std::endl;
}