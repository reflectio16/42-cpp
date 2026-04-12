/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:59:29 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 11:05:29 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon*  _weapon;
        
    public:
        HumanB(std::string name);
        void setWeapon(Weapon& weapon);
        void attack(void);
          
};

#endif