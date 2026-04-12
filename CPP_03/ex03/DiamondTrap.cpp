/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:46:45 by meelma            #+#    #+#             */
/*   Updated: 2026/02/12 17:17:31 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), 
    FragTrap(), _name("default") {
    
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    
    std::cout << "DiamondTrap default constructor called" << std::endl;
} 

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
    ScavTrap(name), FragTrap(name), _name(name) {
    
    _hitPoints = 100;       
    _energyPoints = 50;     
    _attackDamage = 30;
    
    std::cout << "DiamondTrap " << _name << " is built" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), 
    FragTrap(other), _name(other._name) {

    std::cout << "DiamondTrap copy constructor called" << std::endl;
    
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap(other);
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    
    std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {
    
    std::cout << "I am " << _name << " (DiamondTrap)" << std::endl;
    std::cout << "and " << ClapTrap::_name << " (Claptrap)" << std::endl;
}