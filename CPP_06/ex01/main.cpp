/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:21:26 by meelma            #+#    #+#             */
/*   Updated: 2026/05/15 18:09:43 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    
    Data students = { "Merve", 1461, 100 };
  
    uintptr_t raw = Serializer::serialize(&students);
    Data* restored = Serializer::deserialize(raw); 

    std::cout << "Original address: " << &students << std::endl;
    std::cout << "Raw uintptr_t: " << raw << std::endl;
    std::cout << "Restored adress: " << restored << std::endl;
    std::cout << "Match: " << (&students == restored ? "yes" : "no") << std::endl;
    
    std::cout << "\nData via restored pointer:" << std::endl;
    std::cout << " name:  " << restored->name << std::endl;
    std::cout << " id:    " << restored->id << std::endl;
    std::cout << " score: " << restored->score << std::endl;
    
    return 0;
}