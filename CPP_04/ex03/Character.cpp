/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:43:43 by meelma            #+#    #+#             */
/*   Updated: 2026/02/19 20:07:44 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("default") {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    std::cout << "Character constructor is built" << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {

    for (int i = 0; i < 4; i++) {
        if (other._inventory[i] != NULL)
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
            
    }
    std::cout << "Character copy constructor called" << std::endl;
    
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] != NULL)
                delete _inventory[i];
        }
        
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i] != NULL)
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }

    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
    std::cout << "Character destroyed" << std::endl;
}

std::string const & Character::getName() const {
    
    return _name;
}

void Character::equip(AMateria* m) {
    
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) 
        return;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4)
        return;
    if (_inventory[idx] != NULL)
        _inventory[idx]->use(target);
}
