/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:12:06 by meelma            #+#    #+#             */
/*   Updated: 2026/01/28 11:23:14 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    _fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fracBits;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(num * (1 << _fracBits));
}
        
Fixed::Fixed(const Fixed& other) {
    _fixedPointValue = other._fixedPointValue;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
            _fixedPointValue = other._fixedPointValue;
        }
        return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits( int const raw ) {
    _fixedPointValue = raw;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

float Fixed::toFloat( void ) const {
    return (float)_fixedPointValue / (1 << _fracBits);
}

int Fixed::toInt( void ) const {
    return _fixedPointValue >> _fracBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}