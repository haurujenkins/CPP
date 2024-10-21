/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:24:16 by lpr               #+#    #+#             */
/*   Updated: 2024/10/21 15:16:25 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int main()
{
    try {
        std::cout << "\n ------billy------ " << std::endl;
        Bureaucrat billy("billy", 149);
        std::cout << billy << std::endl;
        billy.downGrade();
        std::cout << billy << std::endl;
        billy.downGrade();
        std::cout << billy << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n ------FORM PART (first try)------ \n" << std::endl;
        Bureaucrat tom("tom", 3);
        Form sondage("sondage", 1, 30);
        std::cout << tom << std::endl;
        std::cout << sondage << std::endl;
        sondage.beSigned(tom);
        std::cout << sondage << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n ------FORM PART (second try)------ \n" << std::endl;
        Bureaucrat tom("tom", 3);
        Form sondage("sondage", 1, 30);
        std::cout << tom << std::endl;
        std::cout << sondage << std::endl;
        tom.upGrade();
        tom.upGrade();
        sondage.beSigned(tom);
        tom.signForm(sondage);
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}