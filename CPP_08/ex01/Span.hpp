/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:06:48 by meelma            #+#    #+#             */
/*   Updated: 2026/05/27 18:01:00 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

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






#endif