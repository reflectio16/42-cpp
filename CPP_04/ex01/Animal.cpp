/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:44:02 by meelma            #+#    #+#             */
/*   Updated: 2026/02/18 14:44:04 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal () : _type("Animal") {
    std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal (std::string type) : _type(type) {

    std::cout << "Animal " << type << " is built" << std::endl;
}

Animal::Animal (const Animal& other) : _type(other._type) {
    
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    
    std::cout << "Animal " << _type << " destroyed" << std::endl;
}

void Animal::makeSound() const {
    
    std::cout << "Generic sound" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}