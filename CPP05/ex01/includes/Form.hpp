/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpr <lpr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:20:56 by lpr               #+#    #+#             */
/*   Updated: 2024/10/20 17:52:39 by lpr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(std::string name, int gradeToSign, int gradeToExec);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

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

        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        std::string getStatus() const;
        void beSigned(Bureaucrat& bureaucrat);
    
    private:
        std::string const name;
        bool signature;
        int const gradeToSign;
        int const gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif