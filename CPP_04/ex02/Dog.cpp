/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:59:59 by meelma            #+#    #+#             */
/*   Updated: 2026/02/18 18:11:02 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
   
    if (this != &other) {
        AAnimal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() {
    
    std::cout << "Dog destroyed" << std::endl;
    delete _brain;
}

void Dog::makeSound() const {
    
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}