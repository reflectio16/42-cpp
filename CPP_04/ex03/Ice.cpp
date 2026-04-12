/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:24:48 by meelma            #+#    #+#             */
/*   Updated: 2026/02/19 15:48:05 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
    
    _type = "ice";
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice() {
    
    std::cout << "Ice destroyed" << std::endl;
}

AMateria* Ice::clone() const {
   
    return new Ice(*this);
}

void Ice::use(ICharacter& target) const {
    
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

}