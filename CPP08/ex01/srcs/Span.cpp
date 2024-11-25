/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:22:27 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/25 17:17:37 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& other) : max_size(other.max_size), numbers(other.numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		max_size = other.max_size;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (numbers.size() >= max_size)
		throw std::runtime_error("Cannot add more numbers, span is full");
	numbers.push_back(number);
}

void Span::printNumbers() const {
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

int	Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("not enough numbers to calculate a span");
	
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	int min_span = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < min_span)
		{
			min_span = span;
		}
	}
	return min_span;
}

int Span::longestSpan() const
{
	int min_elem = *std::min_element(numbers.begin(), numbers.end());
	int max_elem = *std::max_element(numbers.begin(), numbers.end());
	
	return max_elem - min_elem;
}