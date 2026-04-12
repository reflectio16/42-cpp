/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:57:43 by meelma            #+#    #+#             */
/*   Updated: 2026/02/18 16:03:54 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor is built" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    
    std::cout << "Brain is destroyed" << std::endl;
}
    
void Brain::setIdeas(int index, std::string idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea; 
}

std::string Brain::getIdeas(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}