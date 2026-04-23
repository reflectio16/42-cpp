/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:13:21 by meelma            #+#    #+#             */
/*   Updated: 2026/04/23 16:29:04 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    
    // Test 1: Creating a valid form and printing it
    std::cout << "=== Test 1: valid form ===" << std::endl;

    try {
        Form contract("Contract", 50, 25);
        std::cout << contract << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    // Test 2: form with sign grade too high ( < 1)
    std::cout << "\n=== Test 2: form with sign grade 0 ===" << std::endl;
    try {
        Form bad("BadForm", 0, 25);
        std::cout << bad << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
    
    // Test 3: form with exec grade too low (> 150)
    std::cout << "\n=== form with exec grade 151 ===" << std::endl;
    try {
        Form bad("BadForm", 25, 151);
        std::cout << bad << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    // Test 4: high-ranked bureaucrat successfully signs
    std::cout << "\n=== Test 4: successful signing ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 5);
        Form report("Report", 50, 25);
        std::cout << "before: " << report << std::endl;
        boss.signForm(report);
        std::cout << "after: " << report << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected execption: " << e.what() << std::endl;
    }
    
    // Test 5: low-ranked bureaucrat fails to sign
    std::cout << "\n=== Test 5: failed signing (grade too low) ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 140);
        Form    report("Report", 50, 25);
        std::cout << "before: " << report << std::endl;
        intern.signForm(report);
        std::cout << "after: " << report << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    // Test 6: bureaucrat at exactly the required grade can sign
    std::cout << "\n=== Test 6: boundary — grade equals required ===" << std::endl;
    try {
        Bureaucrat manager("Manager", 50);
        Form report("Report", 50, 25);
        std::cout << "before : " << report << std::endl;
        manager.signForm(report);
        std::cout << "after: " << report << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << std::endl;
    }

    // Test 7: bureaucrat one below required grade cannot sign
    std::cout << "\n=== Test 7: boundary — one grade below required ===" << std::endl;
    try {
        Bureaucrat almost("Almost", 51);
        Form report("Report", 50, 25);
        std::cout << "before: " << report << std::endl;
        almost.signForm(report);
        std::cout << "after: " << report << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    // Test 8: signing a form twice (second sign is harmless)
    std::cout << "\n=== Test 8: signing an already-signed form ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 5);
        Form report("Report", 50, 25);
        boss.signForm(report);
        boss.signForm(report);
        std::cout << report << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "unexpected exception: " << e.what() << std::endl;
    }

    // Test 9: directly calling beSigned and catching yourself
    std::cout << "\n=== Test 9: direct beSigned call ===" << std::endl;
    try {
        Bureaucrat low("Low", 100);
        Form report("Report", 50, 25);
        report.beSigned(low);
        std::cout << report << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "caught GradeTooLow: " << e.what() << std::endl;
    }

    
    return 0;
}