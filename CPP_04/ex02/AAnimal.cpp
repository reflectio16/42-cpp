/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:58:20 by meelma            #+#    #+#             */
/*   Updated: 2026/02/18 18:10:03 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal () : _type("Animal") {
    std::cout << "Animal default constructor is called" << std::endl;
}

AAnimal::AAnimal (std::string type) : _type(type) {

    std::cout << "Animal " << type << " is built" << std::endl;
}

AAnimal::AAnimal (const AAnimal& other) : _type(other._type) {
    
    std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    
    std::cout << "Animal " << _type << " destroyed" << std::endl;
}

std::string AAnimal::getType() const {
    return _type;
}