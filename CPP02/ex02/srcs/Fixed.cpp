/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:23:45 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/07 15:43:45 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

//default constructor
Fixed::Fixed() : value(0) {
}

//int constructor
Fixed::Fixed(int const value) {
    this->value = value << bits;
}

//float constructor
Fixed::Fixed(float const value) {
    this->value = static_cast<int>(roundf(value * (1 << bits)));
}

//copy constructor
Fixed::Fixed(const Fixed &other) {
    *this = other;
}

//assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

//destructor
Fixed::~Fixed() {
}

//converts the fixed point value to a float
float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->bits));
}

//converts the fixed point value to an integer
int		Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

//surcharge << operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.value = this->value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.value = (this->value * other.value) >> this->bits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.value = (this->value << this->bits) / other.value;
    return result;
}

// Increment and Decrement operators
Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->value--;
    return temp;
}

// Static member functions for min and max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a.value < b.value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.value < b.value) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a.value > b.value) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.value > b.value) ? a : b;
}