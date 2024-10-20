/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpr <lpr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:24:16 by lpr               #+#    #+#             */
/*   Updated: 2024/10/20 17:59:25 by lpr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat billy("billy", 149);
    Bureaucrat tom("tom", 2);
    Bureaucrat lola("lola", 245);
    std::cout << std::endl;
    std::cout << billy << std::endl;
    std::cout << tom << std::endl;
    std::cout << lola << std::endl;
    
    std::cout << "\n ------billy------ " << std::endl;
    billy.downGrade();
    std::cout << billy << std::endl;
    billy.downGrade();
    std::cout << billy << std::endl;

    std::cout << "\n ------tom------ " << std::endl;
    tom.upGrade();
    std::cout << tom << std::endl;
    tom.upGrade();
    std::cout << tom << std::endl;
    std::cout << std::endl;

    std::cout << "\n ------FORM PART------ \n" << std::endl;
    
    Form sondage("sondage", 1, 30);
    std::cout << sondage << std::endl;
    sondage.beSigned(tom);
    std::cout << sondage << std::endl;
    std::cout << std::endl;

    tom.signForm(sondage);
    
    std::cout << std::endl;
    return 0;
}