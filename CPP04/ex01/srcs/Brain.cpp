/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:17:34 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/16 13:15:38 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() : ideas(new std::string[100])
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "empty";
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    delete[] ideas;
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const & brain)
{
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
}

Brain & Brain::operator=(Brain const & brain)
{
    delete[] ideas;
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return *this;
}