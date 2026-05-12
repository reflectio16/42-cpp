/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:51:33 by meelma            #+#    #+#             */
/*   Updated: 2026/05/12 19:24:23 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <climits>   // INT_MIN, INT_MAX
#include <cmath>     // std::isnan, std::isinf
#include <iomanip>   // std::fixed, std::setprecision
#include <limits>    // std::numeric_limits

static bool isInt(const std::string& s) {
    if (s.empty())
        return false;
    size_t i = 0;
    if(s[i] == '-' || s[i] == '+')
        i++;
    if(i == s.length())
        return false;
    while (i < s.length()) {
        if (!std::isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

static bool isFloat(const std::string& s) {
    if (s.empty() || s.length() < 2)
        return false;
    if (s[s.length() - 1] != 'f')
        return false; 
    std::string num = s.substr(0, s.length() - 1);
    if (num.empty())
        return false;
    size_t i = 0;
    if (num[i] == '-' || num[i] == '+')
        i++;
    bool hasDot = false;
    bool hasDigit = false;
    while (i < num.length()) {
        if (num[i] == '.')
            hasDot = true;
        else if (std::isdigit(num[i])) {
            hasDigit = true;
        }
        else {
            return false;
        }
        i++;
    }
    return hasDigit && hasDot;
}

static bool isChar(const std::string& s) {
    if (s.length() != 1)
        return false;
    if (isdigit(s[0]))
        return false;
    return true;
}

static bool isDouble(const std::string& s) {
    if (s.empty() || s.length() < 2)
        return false;
    size_t i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    bool hasDot = false;
    bool hasdigit = false;
    while (i < s.length()) {
        if (s[i] == '.') {
            hasDot = true;
        }
        else if (isdigit(s[i])) {
            hasdigit = true;
        }
        else {
            return false;
        }
        i++;
    }
    return hasdigit && hasDot;
}

static void printChar(double value) {
    
}

static void printInt(double value) {
    
}

static void printFloat(double value) {
    
}

static void printDouble(double value) {
    
}

static void printSpecial(std::string literal) {
     
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {} 

void ScalarConverter::convert(const std::string& literal) {
    double value;
    
    if (literal == "nan" || literal == "nanf" || literal == "+inf"
        || literal == "-inf" || literal == "+inff" || literal == "-inff") {
            printSpecial(literal);
            return;
        }  
    if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isInt(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal)) {
        std::string num = literal.substr(0, literal.length() - 1);
        value = static_cast<double>(std::atof(num.c_str()));
    }
    else if (isDouble(literal))
        value = std::atof(literal.c_str());
    else {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
    
}

