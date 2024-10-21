/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:23:45 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/14 13:33:24 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

//default constructor
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

//int constructor
Fixed::Fixed(int const value) {
    std::cout << "Int constructor called" << std::endl;
    this->value = value << bits;
}

//float constructor
Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(roundf(value * (1 << bits)));
}

//copy constructor
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

//assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

//destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
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