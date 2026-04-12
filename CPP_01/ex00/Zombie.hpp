/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:56:45 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 10:49:15 by meelma           ###   ########.fr       */
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
        Zombie(std::string name);
        ~Zombie();
        void announce ( void );

};

Zombie* newZombie(std::string name );
void    randomChump( std::string name );

#endif