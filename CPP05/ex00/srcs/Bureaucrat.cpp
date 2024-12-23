/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:31:39 by lpr               #+#    #+#             */
/*   Updated: 2024/10/21 13:31:24 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown"), grade(150)
{
    std::cout << "Bureaucrat constructor called" <<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "Bureaucrat constructor called" <<std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
    std::cout << "copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        *this = other;
        std::cout << "assignation operator called" << std::endl;
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::upGrade()
{
    std::cout << "--> upGrade called" << std::endl;
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::downGrade()
{
    std::cout << "<-- downGrade called" << std::endl;
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}