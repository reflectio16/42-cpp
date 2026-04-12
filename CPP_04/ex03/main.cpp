/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:57:08 by meelma            #+#    #+#             */
/*   Updated: 2026/02/19 20:24:57 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    std::cout << std::endl;
    std::cout << "=== Expected Outputs ===" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    
    std::cout << std::endl;
    delete bob;
    delete me;
    delete src;

    /*std::cout << std::endl << "=== Additional Tests ===" << std::endl;
    
    // Test 1: Unknown materia type
    std::cout << std::endl << "--- Test: Unknown materia type ---" << std::endl;
    MateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    AMateria* unknown = src2->createMateria("fire");  // Doesn't exist
    if (unknown == NULL)
        std::cout << "Unknown materia returns NULL: OK" << std::endl;
    
    // Test 2: Full inventory (4 slots)
    std::cout << std::endl << "--- Test: Full inventory ---" << std::endl;
    Character* player = new Character("player");
    player->equip(src2->createMateria("ice"));
    player->equip(src2->createMateria("ice"));
    player->equip(src2->createMateria("ice"));
    player->equip(src2->createMateria("ice"));
    player->equip(src2->createMateria("ice"));  // 5th should be ignored
    
    // Test 3: Use all slots
    std::cout << std::endl << "--- Test: Use all 4 slots ---" << std::endl;
    Character* enemy = new Character("enemy");
    player->use(0, *enemy);
    player->use(1, *enemy);
    player->use(2, *enemy);
    player->use(3, *enemy);
    
    // Test 4: Use invalid slot
    std::cout << std::endl << "--- Test: Invalid slot ---" << std::endl;
    player->use(-1, *enemy);  // Should do nothing
    player->use(4, *enemy);   // Should do nothing
    
    // Test 5: Deep copy Character
    std::cout << std::endl << "--- Test: Deep copy Character ---" << std::endl;
    Character* clone = new Character(*player);
    clone->use(0, *enemy);  // Should work with copied materia
    
    // Test 6: Unequip (doesn't delete)
    std::cout << std::endl << "--- Test: Unequip ---" << std::endl;
    AMateria* saved = src2->createMateria("ice");
    player->equip(saved);  // Won't equip (full), but let's test unequip
    player->unequip(0);    // Unequip slot 0
    player->use(0, *enemy); // Should do nothing now
    
    std::cout << std::endl << "=== Cleanup ===" << std::endl;
    delete enemy;
    delete clone;
    delete player;
    delete src2;
    delete saved;  // We saved the address before unequip*/
    
    return 0;
}