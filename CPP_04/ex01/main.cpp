/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:46:48 by meelma            #+#    #+#             */
/*   Updated: 2026/02/18 16:18:55 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {

    std::string dogIdeas[] = {
        "Chase the ball!",
        "Bark at the door!",
        "Dig a hole!",
        "Nap time!",
        "Eat treats!"
    };

    std::string catIdeas[] = {
        "Knock things off table",
        "Sleep in sunlight",
        "Ignore human",
        "Hunt insivible prey",
        "Demand food at 3am"
    };
    
    const int size = 6;
    Animal* animals[size];

    std::cout << "=== Creating Dogs ====" << std::endl;
    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
    }

    std::cout << std::endl;
    std::cout << "=== Creating Cats ====" << std::endl;
    
    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
    }
    
    std::cout << std::endl;
    std::cout << "=== Testing Deep Copy ====" << std::endl;
    
    Dog original;
    original.getBrain()->setIdeas(0, dogIdeas[0]);

    Dog copy(original);
    copy.getBrain()->setIdeas(0, catIdeas[0]);

    std::cout << std::endl;
    std::cout << "=== Cheking if original and the copy have the same idea ====" << std::endl;
    
    std::cout << original.getBrain()->getIdeas(0) << std::endl;
    std::cout << copy.getBrain()->getIdeas(0) << std::endl;
    
    std::cout << std::endl;
    std::cout << "=== Deleting all Cats and Dogs ====" << std::endl;
    
    for (int i = 0; i < size; i++) {
       delete animals[i];
    }
    
    return 0;
}