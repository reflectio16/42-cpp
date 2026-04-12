/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:59:41 by meelma            #+#    #+#             */
/*   Updated: 2026/02/18 18:10:35 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    
    std::cout << "Cat destroyed" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    
    std::cout << "Miauv Miauv" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}