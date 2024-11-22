/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:35:38 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/22 16:58:28 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), arraySize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arraySize(n)
{
    elements = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T>& other) : arraySize(other.arraySize)
{
    elements = new T[arraySize];
    for (unsigned int i = 0; i < arraySize; i++)
    {
        elements[i] = other.elements[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] elements;

        arraySize = other.arraySize;
        elements = new T[arraySize];
        for (unsigned int i = 0; i < arraySize; i++)
            elements[i] = other.elements[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= arraySize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return arraySize;
}