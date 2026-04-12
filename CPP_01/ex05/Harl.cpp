/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:07:11 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 10:04:40 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
    std::cout << "I love having extra bacon for my ketchup burger";
    std::cout << " I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << " You didn't put enough bacon in my burger!";
    std::cout << " If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free";
    std::cout << " I've been coming for years,";
    std::cout << " whereas you started working here just last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
}

void Harl::complain( std::string level ) {
    
    void (Harl::*funcs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i= 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*funcs[i])();
            break;
        }
    }
}