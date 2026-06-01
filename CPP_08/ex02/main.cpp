/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:04:15 by meelma            #+#    #+#             */
/*   Updated: 2026/06/01 18:36:44 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>


int main() {
    
    MutantStack<int> mstack;
    
    mstack.push(2);
    mstack.push(17);
    
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << std::endl;
    std::cout << " === iterator === " << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        it++;
    }

    std::cout << std::endl;
    std::cout << " === Reverse iterator === " << std::endl;
    MutantStack<int>::reverse_iterator rev_it = mstack.rbegin();
    MutantStack<int>::reverse_iterator rev_end_it = mstack.rend();
    while (rev_it != rev_end_it) {
        std::cout << *rev_it << std::endl;
        rev_it++;
    }
    
    std::cout << std::endl;
    std::cout << " === Const iterator === " << std::endl;
    const MutantStack<int> cmstack(mstack);
    MutantStack<int>::const_iterator cit = cmstack.begin();
    MutantStack<int>::const_iterator cite = cmstack.end();
    while (cit != cite) {
        std::cout << *cit << std::endl;
        cit++;
    }

    std::cout << std::endl;
    std::cout << " === Const Reverse iterator === " << std::endl;
    MutantStack<int>::const_reverse_iterator crit = cmstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = cmstack.rend();
    while(crit != crite) {
        std::cout << *crit << std::endl;
        crit++;
    }

    std::cout << std::endl;
    std::cout << " === === Test with std::list === === " << std::endl;
    
    std::list<int> lstack;
    
    lstack.push_back(2);
    lstack.push_back(17);

    lstack.pop_back();
    std::cout << "size: " << lstack.size() << std::endl;

    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);

    std::cout << std::endl;
    std::cout << " === iterator with std::list === " << std::endl;
    std::list<int>::iterator it_lst = lstack.begin();
    std::list<int>::iterator ite_lst = lstack.end();
    while (it_lst != ite_lst) {
        std::cout << *it_lst << std::endl;
        it_lst++;
    }

    std::cout << std::endl;
    std::cout << " === Reverse iterator with std::list === " << std::endl;
    std::list<int>::reverse_iterator rev_it_lst = lstack.rbegin();
    std::list<int>::reverse_iterator rev_end_it_lst = lstack.rend();
    while (rev_it_lst != rev_end_it_lst) {
        std::cout << *rev_it_lst << std::endl;
        rev_it_lst++;
    }

    return 0;
}
