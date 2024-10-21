/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:00:37 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 17:00:38 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>
#include <string>

class Harl
{
public:
	Harl(void);
	~Harl(void);

	void complain(std::string level);

private:
	static const std::string mood[];

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif