/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:24:16 by lpr               #+#    #+#             */
/*   Updated: 2024/10/21 18:26:38 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
    try {
        std::cout << "\n ------(execute signed shrubbery)------ \n" << std::endl;
        Bureaucrat tom("tom", 15);
        //AForm sondage("sondage", 1, 30);
        ShrubberyCreationForm shrubbery("garden");
        std::cout << tom << std::endl;
        std::cout << shrubbery << std::endl;
        shrubbery.beSigned(tom);
        tom.signForm(shrubbery);
        tom.executeForm(shrubbery);
        
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::FormNotSignedException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    
    try {
        std::cout << "\n ------(execute but not signed)------ \n" << std::endl;
        Bureaucrat billy("billy", 3);
        RobotomyRequestForm robot("robot");
        std::cout << billy << std::endl;
        std::cout << robot << std::endl;
        robot.execute(billy);
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::FormNotSignedException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n ------(execute signed Robotomy)------ \n" << std::endl;
        Bureaucrat billy("billy", 3);
        RobotomyRequestForm robot("robot");
        std::cout << billy << std::endl;
        std::cout << robot << std::endl;
        robot.beSigned(billy);
        std::cout << "\nexecute -->\n";
        robot.execute(billy);
        std::cout << "\n";
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::FormNotSignedException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n ------(execute signed PresidentialPardonForm)------ \n" << std::endl;
        Bureaucrat sophie("sophie", 5);
        PresidentialPardonForm employee("employee");
        std::cout << sophie << std::endl;
        std::cout << employee << std::endl;
        employee.beSigned(sophie);
        std::cout << "\nexecute -->\n";
        employee.execute(sophie);
        std::cout << "\n";
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AForm::FormNotSignedException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}