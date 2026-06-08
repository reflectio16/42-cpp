/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:03:30 by meelma            #+#    #+#             */
/*   Updated: 2026/06/08 17:00:48 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <iostream>
#include <algorithm>
#include <utility>

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
    
    std::vector< std::pair<unsigned int, unsigned int> > pairs;
    unsigned int straggler = 0;
    bool hasStraggler = false;
    
    if (_vec.size() % 2 != 0) {
        straggler = _vec.back();
        hasStraggler = true;
    }
    
    for (size_t i = 0; i + 1 < _vec.size(); i += 2) {

            unsigned int a = _vec[i];
            unsigned int b = _vec[i + 1];
            
            if (a >= b)
                pairs.push_back(std::make_pair(a, b));
            else
                pairs.push_back(std::make_pair(b, a));    
    }
    std::sort(pairs.begin(), pairs.end());

    std::vector<unsigned int> mainChain;
    std::vector<unsigned int> pending;
    
    if (!pairs.empty())
        mainChain.push_back(pairs[0].second); // smaller of the first pair
        
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);  // larger of each pair
    }

    for (size_t i = 1; i < pairs.size(); i++) { // pending elements - skip the first pair
        pending.push_back(pairs[i].second);
    }
    
    // The Jacobsthal-ordered list of pending elements
    std::vector<size_t> order;
    size_t k = pending.size(); // total number of pending elements
    size_t j_prev = 1;
    size_t j_curr = 3; // jacobstal start at j(3) = 3
    
    while (j_prev < k + 1) {
        size_t group_max = (j_curr < k + 1) ? j_curr : k + 1;
        for (size_t b_i = group_max; b_i > j_prev; b_i--) {
            order.push_back(b_i - 2);
        }
        // Advance jacobsthal
        size_t j_next = j_curr + 2 * j_prev;
        j_prev = j_curr;
        j_curr = j_next;
    }

    std::cout << "Insertion order (pending indices):";
    for (size_t i = 0; i < order.size(); i++)
        std::cout << " " << order[i];
    std::cout << std::endl;
    std::cout << "Expected count: " << pending.size() 
          << ", actual: " << order.size() << std::endl;

    for (size_t i = 0; i < order.size(); i++) {
        unsigned int value = pending[order[i]];
        std::vector<unsigned int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    
    if (hasStraggler) {
        std::vector<unsigned int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    _vec = mainChain;
    
    /* temporary debug print to verify:
    std::cout << "Main chain:";
    for (size_t i = 0; i < mainChain.size(); i++)
        std::cout << " " << mainChain[i];
    std::cout << std::endl;

    std::cout << "Pending:";
    for (size_t i = 0; i < pending.size(); i++)
        std::cout << " " << pending[i];
    std::cout << std::endl;

    if (hasStraggler)
        std::cout << "Straggler: " << straggler << std::endl; */ 
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