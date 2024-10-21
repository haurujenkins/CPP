/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:38:55 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/16 12:56:23 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const & dog)
{
    this->type = dog.type;
    this->brain = new Brain(*dog.brain);
}

Dog & Dog::operator=(Dog const & dog)
{
    this->type = dog.type;
    this->brain = new Brain(*dog.brain);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Wouf" << std::endl;
}

void Dog::setIdea(int index, std::string idea)
{
    this->brain->ideas[index] = idea;
}

std::string Dog::getIdea(int index) const
{
    return this->brain->ideas[index];
}