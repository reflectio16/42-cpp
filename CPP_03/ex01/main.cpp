/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:12:18 by meelma            #+#    #+#             */
/*   Updated: 2026/02/11 15:03:50 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");
    
    std::cout << std::endl << "=== ScavTrap Attack ===" << std::endl;
    scav.attack("Enemy");
    
    std::cout << std::endl << "=== ScavTrap Take Damage ===" << std::endl;
    scav.takeDamage(30);
    
    std::cout << std::endl << "=== ScavTrap Repair ===" << std::endl;
    scav.beRepaired(10);
    
    std::cout << std::endl << "=== ScavTrap Special Ability ===" << std::endl;
    scav.guardGate();
    
    std::cout << std::endl << "=== Destruction ===" << std::endl;
    return 0;
}