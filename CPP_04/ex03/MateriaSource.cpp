/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:21:42 by meelma            #+#    #+#             */
/*   Updated: 2026/02/19 19:54:33 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
    
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }

    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    
    for (int i = 0; i < 4; i++) {
        if (other._materias[i] != NULL)
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    
    std::cout << "MateriaSource assignment operator called" << std::endl;

    if (this != &other) {
        
        for (int i = 0; i < 4; i++) {
            if (_materias[i] != NULL)
                delete _materias[i];
        }

        for (int i = 0; i < 4; i++) {
            if (other._materias[i] != NULL)
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    
    for (int i = 0; i < 4; i++) {
        if (_materias[i] != NULL)
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++) {
        if (_materias[i] == NULL) {
            _materias[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {

    for (int i = 0; i < 4; i++) {
        if (_materias[i] != NULL && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
