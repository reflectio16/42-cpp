/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:37:00 by meelma            #+#    #+#             */
/*   Updated: 2026/02/17 18:37:12 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    
    /*std::cout << "=== Wrong Animal Test ===" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "=== WrongCat makes sound ===" << std::endl;
    wrongCat->makeSound();*/

    std::cout << "=== Regular Animal Test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "=== Get Types Test ===" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "=== Dog makes sound ===" << std::endl;
    j->makeSound();
    std::cout << "=== Cat makes sound ===" << std::endl;
    i->makeSound();
    std::cout << "=== Animal makes sound ===" << std::endl;
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    return 0;
}

/*int main() {
    std::cout << "=== Basic Objects ===" << std::endl;
    Dog dog;
    Cat cat;
    
    dog.makeSound();
    cat.makeSound();
    
    std::cout << std::endl << "=== Polymorphism Test ===" << std::endl;
    const Animal* animal = new Animal();
    const Animal* dogPtr = new Dog();
    const Animal* catPtr = new Cat();
    
    std::cout << std::endl << "=== Types ===" << std::endl;
    std::cout << animal->getType() << std::endl;
    std::cout << dogPtr->getType() << std::endl;
    std::cout << catPtr->getType() << std::endl;
    
    std::cout << std::endl << "=== Sounds (polymorphism) ===" << std::endl;
    animal->makeSound();
    dogPtr->makeSound();
    catPtr->makeSound();
    
    std::cout << std::endl << "=== Cleanup ===" << std::endl;
    delete animal;
    delete dogPtr;
    delete catPtr;

    std::cout << std::endl << "=== Stack Objects Destruction ===" << std::endl;
    return 0;
}*/