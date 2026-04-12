/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:42:51 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 09:42:52 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {

    std::string input;
    PhoneBook book;

    while (true) {
        std::cout << "Type [ADD, SEARCH or EXIT]" << std::endl;
        if(!std::getline(std::cin, input))
            break ;
        if (input == "ADD")
            book.addContact();
        else if (input == "SEARCH")
            book.searchContact();
        else if (input == "EXIT")
            break ;
    }
    return (0);
}