/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:53:01 by meelma            #+#    #+#             */
/*   Updated: 2026/05/18 12:51:31 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

Base* generate(void) {
    int n = rand() % 3;
    if (n == 0)
        return new A();
    else if (n == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A ";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B ";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C ";
}

void identify (Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch(std::exception&) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch(std::exception&) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch(std::exception&) {}
}
    
int main() {
    
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        Base* obj = generate();
        std::cout << "Test Random: " << i << ": ";
        identify(obj);
        identify(*obj);
        delete obj;
        std::cout<< std::endl;
    }

    // Explicit tests for each type
    std::cout << "\nForced test:\n";
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    
    identify(a); identify(*a);
    identify(b); identify(*b);
    identify(c); identify(*c);
    
    delete a; delete b; delete c;

    return 0;
}















