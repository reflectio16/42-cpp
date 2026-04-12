/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:40:38 by meelma            #+#    #+#             */
/*   Updated: 2026/01/14 13:40:41 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
    private:
        Contact contacts[8];
        int _contact_count;
        int _oldest_index;
    public:
        PhoneBook();
        void    addContact();
        void    searchContact();
        
};

#endif