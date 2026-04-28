/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:52:25 by meelma            #+#    #+#             */
/*   Updated: 2026/04/28 17:33:48 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));

    // Test 1: print each concrete form
    std::cout << "=== Test 1: print each form type ===" << std::endl;
    try {
        ShrubberyCreationForm   shrub("garden");
        RobotomyRequestForm     robot("Bender");
        PresidentialPardonForm  pardon("Arthur");
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected: " << e.what() << std::endl;
    }
    
    // Test 2: executing an unsigned form
    std::cout << "\n=== Test 2: executing unsigned form ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("backyard");
        boss.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "unexpected: " << e.what() << std::endl;
    }

    // Test 3: signing succeeds but executor's grade is too low
    std::cout << "\n=== Test 3: signed but executor too low ===" << std::endl;
    try {
        Bureaucrat signer("Signer", 20);
        PresidentialPardonForm pardon("Ford");
        signer.signForm(pardon);
        signer.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "unexpected: " << e.what() << std::endl;
    }

    // Test 4: full success — Shrubbery
    std::cout << "\n=== Test 4: Shrubbery full success ===" << std::endl;
    try {
        Bureaucrat  gardener("Gardener", 100);
        ShrubberyCreationForm   shrub("home");
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
        std::cout << "(check current directory for home_shrubbery)" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected: " << e.what() << std::endl;
    }

    // Test 5: full success — Robotomy
    std::cout << "\n=== Test 5: Robotomy full success ===" << std::endl;
    try {
        Bureaucrat  scientist("Scientist", 40);
        RobotomyRequestForm robot("Marvin");
        scientist.signForm(robot);
        scientist.executeForm(robot);  // 50% chance success/failure
    }
    catch (std::exception& e) {
        std::cout << "unexpected: " << e.what() << std::endl;
    } 

    // Test 6: full success — Presidential Pardon
    std::cout << "\n=== Test 6: Pardon full success ===" << std::endl;
    try {
        Bureaucrat  president("President", 1);
        PresidentialPardonForm  pardon("Trillian");
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "unexpected: " << e.what() << std::endl;
    }

    // Test 7: polymorphism — execute through AForm pointer
    std::cout << "\n=== Test 7: polymorphism via AForm pointer ===" << std::endl;
    try {
        Bureaucrat  boss("Boss", 1);
        AForm* form = new RobotomyRequestForm("Zaphod");
        boss.signForm(*form);
        boss.executeForm(*form);  // virtual dispatch → RobotomyRequestForm::executeAction
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "unexpected: " << e.what() << std::endl;
    }

    // Test 8: bureaucrat too low to even sign
    std::cout << "\n=== Test 8: bureaucrat too low to sign ===" << std::endl;
    try {
        Bureaucrat  intern("intern", 150);
        PresidentialPardonForm  pardon("Slartibartfast");
        intern.signForm(pardon);
        intern.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "unexpected: " << e.what() << std::endl;
    }
    
    // Bonus: this would refuse to compile because AForm is abstract
    // AForm a;                              // ← uncomment to verify
    
    return 0;
}

