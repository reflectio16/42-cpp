/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:50:19 by meelma            #+#    #+#             */
/*   Updated: 2026/01/20 17:19:49 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
    
}

void HumanA::attack(void) {
    
    std::cout << _name;
    std::cout << " attacks with their ";
    std::cout << _weapon.getType() << std::endl;
}