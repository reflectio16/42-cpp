/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:01:20 by meelma            #+#    #+#             */
/*   Updated: 2026/01/13 16:10:51 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::setFirstName(std::string input) {
    _firstName = input;
}

void    Contact::setLastName(std::string input) {
    _lastName = input;
}

void    Contact::setNickname(std::string input) {
    _nickname = input;
}

void    Contact::setPhoneNum(std::string input) {
    _phoneNumber = input;
}

void    Contact::setDarkestSecret(std::string input) {
    _darkestSecret = input;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNum() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}