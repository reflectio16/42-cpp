/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:40:28 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 10:54:39 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
    std::string _name;
    
    public:
        Zombie();
        ~Zombie();
        void  announce(void);
        void  setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif