/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:20:56 by lpr               #+#    #+#             */
/*   Updated: 2024/10/21 15:28:14 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExec);
        ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        class GradeTooLowException : public std::exception 
        {
            public :
                virtual const char* what() const throw()
                {
                    return "Grade is too low";
                }
        };
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw() 
                {
                    return "Grade is too high";
                }
        };
        class FormNotSignedException : public std::exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return "Form is not signed";
                }
        };

        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        std::string getStatus() const;
        void beSigned(Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
    
    private:
        std::string const name;
        bool signature;
        int const gradeToSign;
        int const gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif