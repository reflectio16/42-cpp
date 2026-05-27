/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:13:17 by meelma            #+#    #+#             */
/*   Updated: 2026/05/27 18:02:03 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

Span::Span() {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_numbers.size() >= _maxSize)
        throw FullSpanException();
    _numbers.push_back(value);
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw NoSpanException();
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    int min = *std::min_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(max - min);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw NoSpanException();
    std::vector<int> copy(_numbers);
    std::sort(copy.begin(), copy.end());
    unsigned int minDiff = static_cast<unsigned int>(copy[1] - copy[0]);
    for (size_t i = 0; i < copy.size() - 1; i++) {
        unsigned int diff = static_cast<unsigned int>(copy[i + 1] - copy[i]);
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

const char* Span::FullSpanException::what() const throw() {
    return "Span is full";
}

const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers to compute a span";
}