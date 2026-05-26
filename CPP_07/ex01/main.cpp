/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:33:56 by meelma            #+#    #+#             */
/*   Updated: 2026/05/25 12:50:14 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T const &a) {
    std::cout << a << std::endl;
}

template <typename T>
void increment(T &a) {
    a++;
    std::cout << a << std::endl;
}

int main() {
    
    std::cout << "=== Test with non-const print numbers" << std::endl;
    int   numbers[] = {1, 2, 3, 4, 5};
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    std::cout << "=== Test with increment numbers" << std::endl;
    iter(numbers, 5, increment<int>);
    std::cout << std::endl;
    
    std::cout << "=== Test with non-const print string" << std::endl;
    std::string words[] = {"hello", "world"};
    iter(words, 2, print<std::string>);
    std::cout << std::endl;

    std::cout << "=== Test with const print numbers" << std::endl;
    int const constNumbers[] = {10, 20, 30};
    iter(constNumbers, 3, print<int>);
    std::cout << std::endl;

    return 0;
    
}