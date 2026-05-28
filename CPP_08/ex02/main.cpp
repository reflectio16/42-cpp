/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:30:37 by meelma            #+#    #+#             */
/*   Updated: 2026/05/26 13:37:19 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
    
    std::cout << " === Test the empty array=== " << std::endl;
    Array<int> empty_arr;
    std::cout << "size: " << empty_arr.size() << std::endl;
    std::cout << std::endl;
    
    std::cout << " === Test the array with elements=== " << std::endl;
    Array<int> arr(5);
    std::cout << "size: " << arr.size() << std::endl;
    std::cout << std::endl;

    std::cout << " === Test the array with elements and operator[] === " << std::endl;
    Array<int> arr2(5);
    std::cout << "size: " << arr2.size() << std::endl;
    
    for (unsigned int i = 0; i < arr2.size(); i++) 
        std::cout << "arr[" << i <<"] = " << arr2[i] << std::endl;
    
    try {
        std::cout << arr2[10] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: out of bounds" << std::endl;
    }
    std::cout << std::endl;

    std::cout << " === Test copy constructor === " << std::endl;
    Array<int> original(3);
    original[0] = 10;
    original[1] = 20;
    original[2] = 30;
    
    Array<int> copy(original);

    original[0] = 777;
    
    std::cout << "original[0] = " << original[0] << std::endl;

    std::cout << "copy[0] = " << copy[0] << std::endl;
    std::cout << "copy[1] = " << copy[1] << std::endl;
    std::cout << "copy[2] = " << copy[2] << std::endl;
    std::cout << std::endl;
    
    std::cout << " === Test assignment operator === " << std::endl;
    Array<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    
    Array<int> b;   //empty array
    b = a;          // assignment

    a[0] = 999;     // modify original
    
    std::cout << "a[0] = " << a[0] << std::endl;   // expect 999
    std::cout << "b[0] = " << b[0] << std::endl;   // expect 1
    std::cout << "b[1] = " << b[1] << std::endl;   // expect 2
    std::cout << "b[2] = " << b[2] << std::endl;   // expect 3

    b = b;      // self assignment - should not crash - does nothing
    std::cout << "After self-assign, b[0] = " << b[0] << std::endl;   // expect 1
    std::cout << std::endl;
    
    std::cout << "=== Test with std::string ===" << std::endl;
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "world";
    words[2] = "42";

    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << "words[" << i << "] = " << words[i] << std::endl;

    Array<std::string> wordsCopy(words);
    words[0] = "modified";
    std::cout << std::endl;
    std::cout << "After modifying original:" << std::endl;
    std::cout << "words[0] = " << words[0] << std::endl;       // expect "modified"
    std::cout << "wordsCopy[0] = " << wordsCopy[0] << std::endl; // expect "hello"
    
    return 0;
}