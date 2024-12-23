/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:21:00 by lpr               #+#    #+#             */
/*   Updated: 2024/10/21 14:59:12 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : name("random form"), signature(0), gradeToSign(1), gradeToExec(1) 
{
    std::cout << "+ Form constructor called" <<std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), signature(0), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    std::cout << "+ Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    std::cout << "- Form destructor called" << std::endl;
}

Form::Form(Form const &other) : name(other.name), signature(other.signature), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
    std::cout << "= copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        *this = other;
        std::cout << "= assignation operator called" << std::endl;
    }
    return *this;
}

std::string Form::getName() const
{
    return name;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExec() const
{
    return gradeToExec;
}

std::string Form::getStatus() const
{
    if (signature)
        return "yes";
    return "no";
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    std::cout << "[ " << bureaucrat << " try to sign " << *this << " ]" << std::endl;
    if (bureaucrat.getGrade() > gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    else if (getStatus() == "no")
    {
        signature = 1;
        std::cout << this->getName() << " Form was signed by " << bureaucrat.getName() << std::endl;
    }
    else
        std::cout << this->getName() << " Form is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& Form)
{
    os << Form.getName() << ", Form grade to sign : " << Form.getGradeToSign() << ", Form grade to execute : " << Form.getGradeToExec() << ", signature : " << Form.getStatus();
    return os;
}