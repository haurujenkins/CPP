/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:38:14 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/15 20:38:39 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const & cat)
{
    *this = cat;
}

Cat & Cat::operator=(Cat const & cat)
{
    this->type = cat.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Miaou" << std::endl;
}