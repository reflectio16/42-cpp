/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:19:37 by meelma            #+#    #+#             */
/*   Updated: 2026/02/17 18:22:48 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal () : _type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal (std::string type) : _type(type) {

    std::cout << "WrongAnimal " << type << " is built" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal& other) : _type(other._type) {
    
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    
    std::cout << "WrongAnimal " << _type << " destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    
    std::cout << "Generic sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}