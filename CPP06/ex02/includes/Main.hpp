/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:58:56 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/21 16:59:54 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./Base.hpp"
#include "./Classes.hpp"

Base *generate(void);
void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

#endif