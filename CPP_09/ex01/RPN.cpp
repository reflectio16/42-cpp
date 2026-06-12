/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:27:41 by meelma            #+#    #+#             */
/*   Updated: 2026/06/11 17:13:36 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <cctype>
#include <climits>

RPN::RPN() {}

RPN::RPN(const RPN& other) { (void)other; }

RPN& RPN::operator=(const RPN& other) { (void)other; return *this; } 

RPN::~RPN() {}

int RPN::evaluate(const std::string& expr) {
    
    std::stack<int> s;
   
    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];
        if (isspace(c))
            continue;
        if (isdigit(c)) {
             s.push(c - '0');
            continue;
        }
                
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (s.size() < 2) throw ErrorException();
                
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            
            long tmp;
            if (expr[i] == '+')         tmp = static_cast<long>(a) + b;
            else if (expr[i] == '-')    tmp = static_cast<long>(a) - b;
            else if (expr[i] == '*')    tmp = static_cast<long>(a) * b;
            else {
                if (b == 0) throw ErrorException();
                tmp = a / b;
            }
            if (tmp < INT_MIN || tmp > INT_MAX)
                throw ErrorException();
            int result = static_cast<int>(tmp);
            s.push(result);
            continue;
        }
        throw ErrorException(); 
    }
    if (s.size() != 1) throw ErrorException();
    return s.top();
}

const char* RPN::ErrorException::what() const throw() {
    return "Error";
}