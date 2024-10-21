/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:21:00 by lpr               #+#    #+#             */
/*   Updated: 2024/10/21 15:27:46 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : name("random Aform"), signature(0), gradeToSign(1), gradeToExec(1) 
{
    std::cout << "+ Form constructor called" <<std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : name(name), signature(0), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    std::cout << "+ Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "- Form destructor called" << std::endl;
}

AForm::AForm(AForm const &other) : name(other.name), signature(other.signature), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
    std::cout << "= copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        *this = other;
        std::cout << "= assignation operator called" << std::endl;
    }
    return *this;
}

std::string AForm::getName() const
{
    return name;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExec() const
{
    return gradeToExec;
}

std::string AForm::getStatus() const
{
    if (signature)
        return "yes";
    return "no";
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    std::cout << "[ " << bureaucrat << " try to sign " << *this << " ]" << std::endl;
    if (bureaucrat.getGrade() > gradeToSign)
    {
        throw AForm::GradeTooLowException();
    }
    else if (getStatus() == "no")
    {
        signature = 1;
        std::cout << this->getName() << " was signed by " << bureaucrat.getName() << std::endl;
    }
    else
        std::cout << this->getName() << " is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << AForm.getName() << ", grade to sign : " << AForm.getGradeToSign() << ", grade to execute : " << AForm.getGradeToExec() << ", signature : " << AForm.getStatus();
    return os;
}