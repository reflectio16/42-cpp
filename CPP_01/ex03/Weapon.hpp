/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:36:26 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 11:05:41 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string _type;
    
    public:
        Weapon(std::string type);
        void setType(std::string type);
        const std::string& getType(void) const;
    
};

#endif