/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:03:30 by meelma            #+#    #+#             */
/*   Updated: 2026/06/09 17:26:05 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <sys/time.h>
#include <iterator>

PmergeMe::PmergeMe() : _vecTime(0), _lstTime(0) {}

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

std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t k) const {
    std::vector<size_t> order;
    size_t j_prev = 1;
    size_t j_curr = 3;
    while (j_prev < k + 1) {
        size_t group_max = (j_curr < k + 1) ? j_curr : k + 1;
        for (size_t b_i = group_max; b_i > j_prev; b_i--)
            order.push_back(b_i - 2);
        size_t j_next = j_curr + 2 * j_prev;
        j_prev = j_curr;
        j_curr = j_next;
    }
    return order;
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

    std::vector<size_t> order = buildJacobsthalOrder(pending.size());

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
}

void PmergeMe::sortList() {
    typedef std::list<std::pair<unsigned int, unsigned int> > PairList;
    typedef PairList::iterator PairIt;
    typedef std::list<unsigned int>::iterator IntIt;

    unsigned int straggler = 0;
    bool hasStraggler = false;
    
    if (_lst.size() % 2 != 0) {
        straggler = _lst.back();
        hasStraggler = true;
    }
    
    // === Creating the pairs in order ans sort them
    PairList pairs;
    IntIt lit = _lst.begin();
    size_t pairCount = _lst.size() / 2;
    for (size_t i = 0; i < pairCount; i++) {
        unsigned int a = *lit; ++lit;
        unsigned int b = *lit; ++lit;
        if (a >= b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    pairs.sort();

    /* === Pushing the pairs into mainChain list 
    and creating pending list === */
    std::list<unsigned int> mainChain;
    std::list<unsigned int> pending;

    if (!pairs.empty()) 
        mainChain.push_back(pairs.front().second);
    PairIt pIt = pairs.begin();
    while (pIt != pairs.end()) {
        mainChain.push_back(pIt->first);
        ++pIt;
    }

    if (!pairs.empty()) {
        PairIt pIt2 = pairs.begin();
        ++pIt2;                                    // skip the first pair
        while (pIt2 != pairs.end()) {
            pending.push_back(pIt2->second);
            ++pIt2;
        }
    }

    /* === Calling the JacobsthalOrder and putting 
    pending elements into mainCahin  === */
    std::vector<size_t> order = buildJacobsthalOrder(pending.size());
    
    for (size_t i = 0; i < order.size(); i++) {
        std::list<unsigned int>::iterator pIt3 = pending.begin();
        std::advance(pIt3, order[i]);
        unsigned int value = *pIt3;

        std::list<unsigned int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    if (hasStraggler) {
        std::list<unsigned int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    _lst = mainChain;
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

void PmergeMe::displayTimes() const {
    std::cout   << "Time to process a range of " << _vec.size()
                << " elements with std::vector : "
                << std::fixed << std::setprecision(5) << _vecTime << " us"
                << std::endl;
                
    std::cout   << "Time to process a range of " << _vec.size()
                << " elements with std::list   : " 
                << _lstTime << " us"
                << std::endl;
}

void PmergeMe::run(int ac, char** av) {
    parseInput(ac, av);
    displayBefore();
    
    struct timeval start, end;

    gettimeofday(&start, NULL);
    sortVector();
    gettimeofday(&end, NULL);
    _vecTime = (end.tv_sec - start.tv_sec) * 1000000.0
             + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    sortList();
    gettimeofday(&end, NULL);
    _lstTime = (end.tv_sec - start.tv_sec) * 1000000.0
            + (end.tv_usec - start.tv_usec);
    
    displayAfter();
    displayTimes();
}

const char* PmergeMe::InvalidInputException::what() const throw() {
    return "Error";
}