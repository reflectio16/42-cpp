/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:59:36 by meelma            #+#    #+#             */
/*   Updated: 2026/06/02 18:02:06 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main() {
    try {
        BitcoinExchange b;
        b.loadDatabase("data.csv");
        std::cout << "Loaded OK\n";
    } catch (std::exception& e) {
        std::cout << "error: " << e.what() << "\n";
    }
    
    return 0;
}