/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:59:36 by meelma            #+#    #+#             */
/*   Updated: 2026/06/03 17:28:21 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

int main(int ac, char** av) {

    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        exit (1);
    }
    try {
        BitcoinExchange b;
        b.loadDatabase("data.csv");
        b.processInput(av[1]);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}