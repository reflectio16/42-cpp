/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:20:18 by meelma            #+#    #+#             */
/*   Updated: 2026/02/19 20:03:52 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
  
    protected:
        std::string _type;
        
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) const;
        std::string const & getType() const;
};


#endif