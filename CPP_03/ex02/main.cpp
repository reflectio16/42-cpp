/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:57:19 by meelma            #+#    #+#             */
/*   Updated: 2026/02/11 16:23:13 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    std::cout << "=== ClapTrap Test ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    
    std::cout << std::endl << "=== ScavTrap Test ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Target");
    scav.guardGate();
    
    std::cout << std::endl << "=== FragTrap Test ===" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Target");
    frag.highFivesGuys();
    
    std::cout << std::endl << "=== Destruction Order ===" << std::endl;
    return 0;
}
