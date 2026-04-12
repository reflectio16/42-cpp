/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:14:10 by meelma            #+#    #+#             */
/*   Updated: 2026/02/11 15:06:28 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is built" << std::endl;
    
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {

        std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    
    ClapTrap::operator=(other);
    
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    
    std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {

    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " has no energy or health to attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ",";
    std::cout << " causing " << _attackDamage << " points of damage!" << std::endl; 
}

void ScavTrap::guardGate() {
    
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
