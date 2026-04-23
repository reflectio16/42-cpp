/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:50:31 by meelma            #+#    #+#             */
/*   Updated: 2026/04/22 15:20:00 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    
    // Test 1: valid construction and printing
    std::cout << "=== Test 1: valid bureaucrat ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 42);
        std::cout << alice << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    // Test 2: grade too high at construction (grade < 1)
    std::cout << "\n=== Test 2: construction with grade 0 ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 0);
        std::cout << bob << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "caught GradeTooHigh: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "caught other: " << e.what() << std::endl;
    }

    // Test 3: grade too low at construction (grade > 150)
    std::cout << "\n=== Test 3: construction with grade 151 ===" << std::endl;
    try {
        Bureaucrat carol("Carol", 151);
        std::cout << carol << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "caught GradeTooLow: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    // Test 4: normal increment and decrement
    std::cout << "\n=== Test 4: increment and decrement ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 50);
        std::cout << dave << std::endl;
        dave.incrementGrade();
        std::cout << "after increment: " << dave << std::endl;
        dave.decrementGrade();
        dave.decrementGrade();
        std::cout << "after two decrements: " << dave << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    // Test 5: incrementing at grade 1 (upper boundary)
    std::cout << "\n=== Test 5: incrementing at grade 1 ===" << std::endl;
    try {
        Bureaucrat eve("Eve", 1);
        std::cout << eve << std::endl;
        eve.incrementGrade();  // should throw
        std::cout << eve << std::endl;  // never reached
    }
    catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
    
    // Test 6: decrementing at grade 150 (lower boundary)
    std::cout << "\n=== Test 6: decrementing at grade 150 ===" << std::endl;
    try {
        Bureaucrat frank("Frank", 150);
        std::cout << frank << std::endl;
        frank.decrementGrade();  // should throw
        std::cout << frank << std::endl;  // never reached
    }
    catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    // Test 7: boundary grades 1 and 150 are valid
    std::cout << "\n=== Test 7: boundaries 1 and 150 are valid ===" << std::endl;
    try {
        Bureaucrat top("Top", 1);
        Bureaucrat bottom("Bottom", 150);
        std::cout << top << std::endl;
        std::cout << bottom << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    // Test 8: copy construction and assignment
    std::cout << "\n=== Test 8: copy and assignment ===" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "original: " << original << std::endl;
        std::cout << "copy:     " << copy << std::endl;

        Bureaucrat assigned("Assigned", 100);
        assigned = original;
        std::cout << "assigned: " << assigned << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    return 0;
    
}