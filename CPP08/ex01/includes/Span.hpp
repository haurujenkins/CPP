/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:25 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/25 17:17:31 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <climits>

class Span
{
	private:
		unsigned int max_size;
		std::vector<int> numbers;
	
	public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
		
		void addNumber(int number);
        void printNumbers() const;
        int shortestSpan() const;
        int longestSpan() const;
        
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            unsigned int range_size = std::distance(begin, end);

            if (numbers.size() + range_size > max_size)
            {
                throw std::runtime_error("Not enough space to add thi srange");
            }
            numbers.insert(numbers.end(), begin, end);
        }
};

#endif