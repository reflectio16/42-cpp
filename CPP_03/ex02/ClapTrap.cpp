/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:26:46 by meelma            #+#    #+#             */
/*   Updated: 2026/02/11 15:26:48 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    
    std::cout << "ClapTrap " << _name << " is built" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), 
    _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {

        std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    
    std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {

    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy or health to attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ",";
    std::cout << " causing " << _attackDamage << " points of damage!" << std::endl;
    
}

void ClapTrap::takeDamage(unsigned int amount) {
    
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage! HP: " << _hitPoints << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount) {

    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy or health to repair!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount;
    std::cout << " HP! HP: " << _hitPoints << std::endl;
}
