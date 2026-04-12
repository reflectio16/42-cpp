/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:39:49 by meelma            #+#    #+#             */
/*   Updated: 2026/01/14 16:34:24 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    _contact_count = 0;
    _oldest_index = 0;
}

std::string getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    while (input.empty()) {
        std::cout << "Field cannot be empty." << "\n" << prompt;
        std::getline(std::cin, input);
    }
    return input;
}

void    PhoneBook::addContact() {
   
    contacts[_oldest_index].setFirstName(getInput("Enter First Name: "));
    contacts[_oldest_index].setLastName(getInput("Enter Last Name: "));
    contacts[_oldest_index].setNickname(getInput("Enter Nickname: "));
    contacts[_oldest_index].setPhoneNum(getInput("Enter Phone Number: "));
    contacts[_oldest_index].setDarkestSecret(getInput("Enter Darkest Secret: "));
    
    _oldest_index = (_oldest_index + 1) % 8;

    while (_contact_count < 8)
        _contact_count++;
}

std::string formatLine(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    else {
        while (str.length() < 10) {
            str = " " + str;
        }
        return str;
    }
}

void    PhoneBook::searchContact() {

    if (_contact_count == 0) {
        std::cout << "There is no saved contact!" << std::endl;
        return ;
    }
        
    for (int i = 0; i < _contact_count; i++) {
        std::cout << formatLine(std::to_string(i)) << "|";
        std::cout << formatLine(contacts[i].getFirstName()) << "|";
        std::cout << formatLine(contacts[i].getLastName()) << "|";
        std::cout << formatLine(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter the index number: ";
    int _index;
    if (!(std::cin >> _index)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid index number! Please try again." << std::endl;
        return ;
    }
    std::cin.ignore();
    if (_index >= 0 && _index < _contact_count) { 
    std::cout << "First Name: " << contacts[_index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[_index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[_index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[_index].getPhoneNum() << std::endl;
    std::cout << "Darkest Secret: " << contacts[_index].getDarkestSecret() << std::endl;
    }
    else {
        std::cout << "Invalid index number! Please try again." << std::endl;
    }
}