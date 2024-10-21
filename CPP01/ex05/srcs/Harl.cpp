/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:00:47 by lle-pier          #+#    #+#             */
/*   Updated: 2024/08/19 11:12:26 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

std::string const Harl::mood[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void Harl::complain(std::string level)
{
	static void (Harl::*log[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	std::size_t i = 0;
	while (i < 4 && mood[i] != level)
		++i;
	if (i == 4)
	{
		std::cout << "sorry i don't undertsand" << std::endl;
		return;
	}
	return (this->*log[i])();
}

void Harl::debug(void) { std::cout << "[DEBUG]" <<  "i don't want to work today" << std::endl; }
void Harl::info(void) { std::cout << "[INFO]" << "today is the first day of the rest of your life" << std::endl; }
void Harl::warning(void) { std::cout << "[WARNING]" << "becareful this is a warning message, you should care" << std::endl; }
void Harl::error(void) { std::cout << "[ERROR]" << "404" << std::endl; }

