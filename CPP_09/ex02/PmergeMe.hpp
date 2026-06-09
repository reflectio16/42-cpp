/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:59:26 by meelma            #+#    #+#             */
/*   Updated: 2026/06/09 17:24:47 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <exception>
#include <string>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe& operator=(const PmergeMe&);
        ~PmergeMe();
        
        void run(int ac, char** av);
        
        class InvalidInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
    private:
        std::vector<unsigned int>   _vec;
        std::list<unsigned int>     _lst;
        double  _vecTime;
        double  _lstTime;

        std::vector<size_t> buildJacobsthalOrder(size_t k) const;

        void parseInput(int ac, char** av);
        unsigned int parseOne(const std::string& s);
        void sortVector();
        void sortList();
        void displayBefore() const;
        void displayAfter() const;
        void displayTimes() const;
   
};

#endif