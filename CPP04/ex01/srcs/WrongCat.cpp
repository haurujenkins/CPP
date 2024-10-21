/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:59:26 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/15 20:59:39 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & wrongCat)
{
    *this = wrongCat;
}

WrongCat & WrongCat::operator=(WrongCat const & wrongCat)
{
    this->type = wrongCat.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}