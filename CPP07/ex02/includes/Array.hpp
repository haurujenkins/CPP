/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:25 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/22 16:57:00 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int arraySize;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        Array<T>& operator=(const Array<T>& other);
        T& operator[](unsigned int index);
        ~Array();

        unsigned int size() const;
};

#include "../srcs/Array.tpp"

#endif