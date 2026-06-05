/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:03:30 by meelma            #+#    #+#             */
/*   Updated: 2026/06/05 16:24:03 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe&) {}

PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }

PmergeMe::~PmergeMe() {}

unsigned int PmergeMe::parseOne(const std::string& s) {
    if (s.empty()) throw InvalidInputException();
    for (size_t i = 0; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9') throw InvalidInputException();
    errno = 0;
    char* end;
    unsigned long v = std::strtoul(s.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || v > UINT_MAX)
        throw InvalidInputException();
    return static_cast<unsigned int>(v);
}

void PmergeMe::parseInput(int ac, char** av) {
    if (ac < 2) throw InvalidInputException();
    for (int i = 1; i < ac; i++) {
        unsigned int x = parseOne(av[i]);
        _vec.push_back(x);
        _lst.push_back(x);
    }
}

void PmergeMe::sortVector() {
    std::sort(_vec.begin(), _vec.end());
}

void PmergeMe::sortList() {
    _lst.sort();
}

void PmergeMe::displayBefore() const {
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); i++) 
        std::cout << " " << _vec[i];
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const {
    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); i++) 
        std::cout << " " << _vec[i];
    std::cout << std::endl;
}

void PmergeMe::run(int ac, char** av) {
    parseInput(ac, av);
    displayBefore();
    sortVector();
    sortList();
    displayAfter();
}

const char* PmergeMe::InvalidInputException::what() const throw() {
    return "Error";
}