/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:38:14 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/16 13:19:27 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const & cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = cat.type;
    this->brain = new Brain(*cat.brain);
}

Cat & Cat::operator=(Cat const & other)
{
    std::cout << "Cat assignation operator called" << std::endl;
    type = other.type;
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Miaou" << std::endl;
}

void Cat::setIdea(int index, std::string idea)
{
    this->brain->ideas[index] = idea;
}

std::string Cat::getIdea(int index) const
{
    return this->brain->ideas[index];
}