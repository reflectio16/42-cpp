/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:11:40 by meelma            #+#    #+#             */
/*   Updated: 2026/02/12 17:12:51 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== DiamondTrap Test ===" << std::endl;
    DiamondTrap diamond("Diamondy");
    
    std::cout << std::endl << "=== DiamondTrap Attack ===" << std::endl;
    diamond.attack("Target");
    
    std::cout << std::endl << "=== DiamondTrap Special Abilities ===" << std::endl;
    diamond.guardGate();
    diamond.highFivesGuys();
    
    std::cout << std::endl << "=== Who Am I ===" << std::endl;
    diamond.whoAmI();
    
    std::cout << std::endl << "=== Destruction Order ===" << std::endl;
    return 0;
}