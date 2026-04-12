/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:34:39 by meelma            #+#    #+#             */
/*   Updated: 2026/01/20 15:34:40 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {

    int count = 5;
    Zombie* horde = zombieHorde(count, "Walker");

    for (int i = 0; i < count; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}