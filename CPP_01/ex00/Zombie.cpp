/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:56:51 by meelma            #+#    #+#             */
/*   Updated: 2026/01/20 13:17:52 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    _name = name;
}

void Zombie::announce(void) {
    std::cout << _name;
    std::cout << ": ";
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name;
    std::cout << " is destroyed!" << std::endl;
}