/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:57:41 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/21 15:20:03 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

unsigned long Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<unsigned long>(ptr);
}

Data *Serializer::deserialize(unsigned long raw)
{
    return reinterpret_cast<Data *>(raw);
}