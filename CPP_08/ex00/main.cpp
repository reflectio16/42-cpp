/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:52:41 by meelma            #+#    #+#             */
/*   Updated: 2026/05/28 17:09:05 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    
    std::cout << " === Test 1: Vector, value found === " << std::endl;
    {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        try {
            std::vector<int>::iterator it = easyfind(v, 20);
            std::cout << *it << std::endl;
        } catch (std::exception& e) {
            std::cout << "Test 1 unexpectedly trew: " << e.what() << std::endl;
        }
    }
    
    std::cout << std::endl;
    std::cout << " === Test 1: Vector, value NOT found === " << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        try {
            easyfind(v, 99);
            std::cout << "Test 2 should have thrown" << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << std::endl;
        std::cout << " === Test 3: List, Value Found === " << std::endl;
        {
            std::list<int> list;
            list.push_back(5);
            list.push_back(10);
            list.push_back(15);
            try {
                std::list<int>::iterator it = easyfind(list, 10);
                std::cout << *it << std::endl;
            } catch(std::exception& e) {
                std::cout << e.what() << std::endl;
            } 
        }

        std::cout << std::endl;
        std::cout << " === Test 4: Empty Container  === " << std::endl;
        {
            std::vector<int> d;
            try {
                easyfind(v, 42);
                std::cout << "Test 4 should have thrown" << std::endl;
            } catch(std::exception& e) {
                std::cout << "Test 4 (empty container): " << e.what() << std::endl;
            }
            
        }
    }

    return 0;
}

