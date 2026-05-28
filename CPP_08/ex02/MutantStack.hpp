/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:37:36 by meelma            #+#    #+#             */
/*   Updated: 2026/05/28 17:06:56 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack() {}
        
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { return this->c.begin(); } 
        iterator end() { return this->c.end(); }
        
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }
};

#endif