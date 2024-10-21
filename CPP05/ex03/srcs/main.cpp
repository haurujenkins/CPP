/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:24:16 by lpr               #+#    #+#             */
/*   Updated: 2024/10/21 18:02:44 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
    try {
        AForm *MyForm;
        Intern CoffeeGuy;
        MyForm = CoffeeGuy.makeForm("robotomy request", "Bender");
        std::cout << *MyForm << std::endl;
        std::cout << "----------------" << std::endl;
        Bureaucrat tom("tom", 15);
        std::cout << tom << std::endl;
        MyForm->beSigned(tom);
        tom.executeForm(*MyForm);
        delete MyForm;
        
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
    } catch (const Intern::UnknownFormException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}