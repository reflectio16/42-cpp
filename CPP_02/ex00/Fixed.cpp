/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:32:03 by meelma            #+#    #+#             */
/*   Updated: 2026/01/27 16:59:41 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    _fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
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