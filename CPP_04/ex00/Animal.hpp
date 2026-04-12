/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:14:47 by meelma            #+#    #+#             */
/*   Updated: 2026/02/17 15:49:53 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};

#endif