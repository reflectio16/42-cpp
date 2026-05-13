/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:51:33 by meelma            #+#    #+#             */
/*   Updated: 2026/05/13 16:38:24 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <climits>   // INT_MIN, INT_MAX
#include <cmath>     // std::isnan, std::isinf
#include <limits>    // std::numeric_limits

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

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
        if (num[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        }
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
    if (std::isdigit(s[0]))
        return false;
    if (!std::isprint(s[0]))
        return false;
    if (s[0] == '.' || s[0] == '+' || s[0] == '-')
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
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(s[i])) {
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
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    
}

static void printFloat(double value) {
    float f = static_cast<float>(value);
    std::cout << "float: " << f;
    if (!std::isnan(f) && !std::isinf(f)
        && f >= INT_MIN
        && f <= INT_MAX
        && f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static void printDouble(double value) {
    std::cout << "double: " << value;
    if (!std::isnan(value) && !std::isinf(value)
        && value >= INT_MIN
        && value <= INT_MAX
        && value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << std::endl;    
}

void ScalarConverter::convert(const std::string& literal) {
    double value;
    
    if (literal == "nan" || literal == "nanf")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf" || literal == "+inff")
        value = std::numeric_limits<double>::infinity();
    else if (literal == "-inf" || literal == "-inff")
        value = -std::numeric_limits<double>::infinity();
    else if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isInt(literal))
        value = std::atof(literal.c_str());
    else if (isFloat(literal)) {
        std::string num = literal.substr(0, literal.length() - 1);
        value = std::atof(num.c_str());
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

