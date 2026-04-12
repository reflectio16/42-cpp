/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:34:50 by meelma            #+#    #+#             */
/*   Updated: 2026/02/19 20:03:45 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
    
    std::cout << "AMateria default constructor called" << std::endl;
    
}

AMateria::AMateria(std::string const & type) : _type(type) {
    
    std::cout << "AMateria constructor is built" << std::endl;
    
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    
    std::cout << "AMateria copy assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destroyed" << std::endl;
}

void AMateria::use(ICharacter& target) const {
    
}

std::string const & AMateria::getType() const {
    
    return _type;
}