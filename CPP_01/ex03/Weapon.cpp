/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:41:40 by meelma            #+#    #+#             */
/*   Updated: 2026/01/20 17:29:29 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
    
}

void Weapon::setType(std::string type) {
    _type = type;
}

const std::string& Weapon::getType( void ) const {
    return _type;
}

