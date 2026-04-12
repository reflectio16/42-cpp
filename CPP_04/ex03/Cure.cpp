/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:30:19 by meelma            #+#    #+#             */
/*   Updated: 2026/02/19 16:37:20 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {

    _type = "cure";
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destroyed" << std::endl;
}

AMateria* Cure::clone() const {
    
    return new Cure(*this);
}

void Cure::use(ICharacter& target) const {
    
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}