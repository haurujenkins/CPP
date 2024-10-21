/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:48:08 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/21 18:02:36 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "+ Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    *this = other;
    std::cout << "= copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        *this = other;
        std::cout << "= assignation operator called" << std::endl;
    }
    return *this;
}

Intern::~Intern()
{
    std::cout << "- Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    if (name == "robotomy request")
    {
        std::cout << "Intern creates " << name << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (name == "presidential pardon")
    {
        std::cout << "Intern creates " << name << std::endl;
        return new PresidentialPardonForm(target);
    }
    else if (name == "shrubbery creation")
    {
        std::cout << "Intern creates " << name << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else
        throw Intern::UnknownFormException();
}