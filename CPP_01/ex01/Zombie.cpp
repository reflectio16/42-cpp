/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:34:44 by meelma            #+#    #+#             */
/*   Updated: 2026/01/20 15:34:45 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {

}

void Zombie::setName (std::string name) {
    _name = name;
}

void Zombie::announce() {
    std::cout << _name;
    std::cout << ":";
    std::cout << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name;
    std::cout << " is destroyed!" << std::endl;
}
