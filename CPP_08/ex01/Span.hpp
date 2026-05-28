/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:06:48 by meelma            #+#    #+#             */
/*   Updated: 2026/05/28 10:57:15 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <iterator>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int value);
        
        template <typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end);
        
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class FullSpanException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NoSpanException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    
    private:
        unsigned int        _maxSize;
        std::vector<int>    _numbers;
        
};

template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end) {
    unsigned int range_len = std::distance(begin, end);
    if (_numbers.size() + range_len >_maxSize)
        throw FullSpanException();
    _numbers.reserve(_numbers.size() + range_len);
    _numbers.insert(_numbers.end(), begin, end);
    
}




#endif