/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:44:39 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/22 14:17:23 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

class Serializer
{
    private:
        Serializer();
    public:
        static unsigned long serialize(Data *ptr);
        static Data *deserialize(unsigned long raw);
};

#endif