/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:36:20 by meelma            #+#    #+#             */
/*   Updated: 2026/04/28 19:03:28 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    // Test 1: the example from the subject
    std::cout << "=== Test 1: subject example — robotomy request ===" << std::endl;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    // Test 2: shrubbery creation
    std::cout << "\n=== Test 2: shrubbery creation ===" << std::endl;
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (scf) {
        std::cout << *scf << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    // Test 3: presidential pardon
    std::cout << "\n=== Test 3: presidential pardon ===" << std::endl;
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (ppf) {
        std::cout << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    // Test 4: unknown form name
    std::cout << "\n=== Test 4: unknown form name ===" << std::endl;
    AForm* unknown = someRandomIntern.makeForm("coffee request", "Boss");
    if (unknown) {
        std::cout << "should not get here" << std::endl;
        delete unknown;
    }
    else {
        std::cout << "(makeForm returned NULL as expected)" << std::endl;
    }

    // Test 5: case sensitivity — "Robotomy Request" with capital letters should fail
    std::cout << "\n=== Test 5: case sensitivity ===" << std::endl;
    AForm* wrong = someRandomIntern.makeForm("Robotomy Request", "Bender");
    if (wrong) {
        std::cout << "should not get here" << std::endl;
        delete wrong;
    }
    
    return 0;
}

