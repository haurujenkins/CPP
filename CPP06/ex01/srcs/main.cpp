/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:59:43 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/21 16:40:09 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(void)
{
    Data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";

    unsigned long serialized = Serializer::serialize(&data);
    
    Data *deserialized = Serializer::deserialize(serialized);

    if (deserialized->s1 == data.s1 && deserialized->n == data.n && deserialized->s2 == data.s2)
        std::cout << "Data successfully serialized and deserialized" << std::endl;
    else
        std::cout << "Data not successfully serialized and deserialized" << std::endl;

    std::cout << "\nDeserialized data:" << std::endl;
    std::cout << "s1: " << deserialized->s1;
    std::cout << " | n: " << deserialized->n;
    std::cout << " | s2: " << deserialized->s2 << std::endl;
}