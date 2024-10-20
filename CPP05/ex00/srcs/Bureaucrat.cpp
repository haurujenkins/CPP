/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpr <lpr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:31:39 by lpr               #+#    #+#             */
/*   Updated: 2024/10/20 15:55:01 by lpr              ###   ########.fr       */
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
    try {
        if (grade < 1)
        {
            this->grade = 1;
            throw Bureaucrat::GradeTooHighException();
        } else if (grade > 150)
        {
            this->grade = 150;
            throw Bureaucrat::GradeTooLowException();
        }
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
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
    try {
        if (grade - 1 < 1)
        {
            throw Bureaucrat::GradeTooHighException();
        }
        grade--;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Bureaucrat::downGrade()
{
    try {
        if (grade + 1 > 150)
        {
            throw Bureaucrat::GradeTooLowException();
        }
        grade++;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}