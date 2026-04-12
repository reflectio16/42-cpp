/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:55:27 by meelma            #+#    #+#             */
/*   Updated: 2026/01/28 17:01:02 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    _fixedPointValue = 0;
}

Fixed::Fixed(const int value) {
    _fixedPointValue = value << _fracBits;
}

Fixed::Fixed(const float num) {
    _fixedPointValue = roundf(num * (1 << _fracBits));
}
        
Fixed::Fixed(const Fixed& other) {
    _fixedPointValue = other._fixedPointValue;
}

Fixed& Fixed::operator = (const Fixed& other) {
    if (this != &other) {
            _fixedPointValue = other._fixedPointValue;
        }
        return *this;
}

Fixed::~Fixed() {
    
}

void Fixed::setRawBits( int const raw ) {
    _fixedPointValue = raw;
}

int Fixed::getRawBits( void ) const {
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

bool operator<(const Fixed& a, const Fixed& b) {
    return a.getRawBits() < b.getRawBits();
}

bool operator>(const Fixed& a, const Fixed& b) {
    return a.getRawBits() > b.getRawBits();
}
bool operator<=(const Fixed& a, const Fixed& b) {
    return a.getRawBits() <= b.getRawBits();
}

bool operator>=(const Fixed& a, const Fixed& b) {
    return a.getRawBits() >= b.getRawBits();
}

bool operator==(const Fixed& a, const Fixed& b) {
    return a.getRawBits() == b.getRawBits();
}

bool operator!=(const Fixed& a, const Fixed& b) {
    return a.getRawBits() != b.getRawBits();
}

Fixed operator+(const Fixed& a, const Fixed& b) {
    Fixed result;
    result.setRawBits(a.getRawBits() + b.getRawBits());
    return result;
}

Fixed operator-(const Fixed& a, const Fixed& b) {
    Fixed result;
    result.setRawBits(a.getRawBits() - b.getRawBits());
    return result;
}

Fixed operator*(const Fixed& a, const Fixed& b) {
    Fixed result;
    result.setRawBits((a.getRawBits() * b.getRawBits()) >> 8);
    return result;
}

Fixed operator/(const Fixed& a, const Fixed& b) {
    Fixed result;
    result.setRawBits((a.getRawBits() << 8 ) / b.getRawBits());
    return result;
}

Fixed& Fixed::operator++() {
    _fixedPointValue++;
    return *this;
}

Fixed& Fixed::operator--() {
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _fixedPointValue++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
}