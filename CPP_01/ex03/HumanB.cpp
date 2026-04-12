/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:00:54 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 11:05:24 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
    
}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}

void HumanB::attack(void) {
    
    if (_weapon) {
        std::cout << _name;
        std::cout << " attacks with their ";
        std::cout << _weapon->getType() << std::endl;
    }
    else {
        std::cout << _name;
        std::cout << " has no weapon!" << std::endl;
    }
    
}