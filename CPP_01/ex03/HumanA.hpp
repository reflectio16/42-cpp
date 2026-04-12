/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:46:43 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 11:05:19 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon&   _weapon;
        
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack(void);
          
};

#endif