/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:55:04 by meelma            #+#    #+#             */
/*   Updated: 2026/02/10 13:20:15 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap robot1("Robot1");
    ClapTrap robot2("Robot2");
    ClapTrap defaultRobot;

    std::cout << std::endl << "=== Testing Copy Constructor ===" << std::endl;
    ClapTrap copyRobot(robot1);

    std::cout << std::endl << "=== Testing Assignment Operator ===" << std::endl;
    ClapTrap assignRobot;
    assignRobot = robot2;

    std::cout << std::endl << "=== Testing Attack ===" << std::endl;
    robot1.attack("Robot2");
    robot1.attack("Robot2");

    std::cout << std::endl << "=== Testing Take Damage ===" << std::endl;
    robot2.takeDamage(3);
    robot2.takeDamage(5);

    std::cout << std::endl << "=== Testing Repair ===" << std::endl;
    robot2.beRepaired(2);
    robot2.beRepaired(4);

    std::cout << std::endl << "=== Testing Energy Depletion ===" << std::endl;
    ClapTrap tired("TiredBot");
    for (int i = 0; i < 12; i++) {
        std::cout << "Attack #" << i + 1 << ": ";
        tired.attack("Target");
    }

    std::cout << std::endl << "=== Testing Fatal Damage ===" << std::endl;
    ClapTrap weak("WeakBot");
    weak.takeDamage(15);
    std::cout << "Trying to attack with 0 HP:" << std::endl;
    weak.attack("Someone");
    std::cout << "Trying to repair with 0 HP:" << std::endl;
    weak.beRepaired(5);

    std::cout << std::endl << "=== Destructors Called ===" << std::endl;
    return 0;
}