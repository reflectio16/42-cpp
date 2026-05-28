/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:08:06 by meelma            #+#    #+#             */
/*   Updated: 2026/05/28 11:48:01 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    srand(time(NULL));
    
    std::cout << "=== Test 1: Subject's example test === " << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << std::endl;
    std::cout << "=== Test 2: No span exception === " << std::endl;
    Span a = Span();
    a.addNumber(7);
    try {
        std::cout << a.shortestSpan() << std::endl;
    } catch(std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "=== Test 3: Full span exception === " << std::endl;
    Span b = Span(3);

    try {
        b.addNumber(9);
        b.addNumber(12);
        b.addNumber(88);
        b.addNumber(15);
        std::cout << b.shortestSpan() << std::endl;
    } catch(std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "=== Test 4: addNumbers Range === " << std::endl;
    Span c = Span(5);
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(100);
    vec.push_back(50);
    c.addNumbers(vec.begin(), vec.end());
    std::cout << c.shortestSpan() << std::endl;
    std::cout << c.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << "=== Test 5: 10,000 numbers === " << std::endl;
    Span big = Span(10000);
    for (int i = 0; i < 10000; i++)
        big.addNumber(rand());
    std::cout << "shortest: " << big.shortestSpan() << std::endl;
    std::cout << "longest: " << big.longestSpan() << std::endl;
    
    return 0;
}
