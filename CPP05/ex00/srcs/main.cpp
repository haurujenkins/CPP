/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:24:16 by lpr               #+#    #+#             */
/*   Updated: 2024/10/21 13:36:32 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

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
    std::cout << std::endl;
    try {
        std::cout << "\n ------tom------- " << std::endl;
        Bureaucrat tom("tom", 2);
        std::cout << tom << std::endl;
        tom.upGrade();
        std::cout << tom << std::endl;
        tom.upGrade();
        std::cout << tom << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}