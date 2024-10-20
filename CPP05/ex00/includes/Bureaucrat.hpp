/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpr <lpr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:31:37 by lpr               #+#    #+#             */
/*   Updated: 2024/10/20 16:34:17 by lpr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string myname, int mygrade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat& other);

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
        int getGrade() const;
        void upGrade();
        void downGrade();
        
    private:
        std::string const name;
        int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);