/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:00:40 by meelma            #+#    #+#             */
/*   Updated: 2026/01/24 15:38:49 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        
    public:
        void complain( std::string level );
        
};

#endif
