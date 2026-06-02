/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:26:34 by meelma            #+#    #+#             */
/*   Updated: 2026/06/02 19:32:02 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _db(other._db){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool isValidDate(const std::string& s) {
    if (s.size() != 10)
        return false;
    if ('-' != s[4] || '-' != s[7])
        return false;
    for (size_t i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    int y = std::atoi(s.substr(0, 4).c_str());
    int m = std::atoi(s.substr(5, 2).c_str());
    int d = std::atoi(s.substr(8, 2).c_str());
    if (m < 1 || m > 12) 
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (m == 2 && leap) daysInMonth[1] = 29;
    if (d < 1 || d > daysInMonth[m - 1]) 
        return false;
    return true;
}

/* static bool isValidValue() ==> TO DO
    with strtod + errno to handle 
    - negative / 
    - too-large /
    - unparseable
*/  
    
void BitcoinExchange::loadDatabase(const std::string& path) {
    
    std::ifstream file(path.c_str());
    if (!file.is_open())
        throw CannotOpenFileException();
    std::string line;
    std::getline(file, line);
    while (std::getline(file,line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            throw MalformedLineException();
        std::string date = line.substr(0, pos);
        std::string rate_str = line.substr(pos + 1);
        float rate;
        std::istringstream iss(rate_str);
        iss >> rate;
        if (iss.fail())
            throw MalformedLineException();
        _db[date] = rate;
    }
}

void BitcoinExchange::processInput(const std::string& path) {
    std::ifstream input(path.c_str());
    if (!input.is_open())
        throw CannotOpenFileException();
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line)) {
        if (line.empty())
            continue;
        size_t pos = line.find(" | ");
        if (pos == std::string::npos) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }  
        std::string date = line.substr(0, pos);
        if(!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }
        std::string value_str = line.substr(pos + 3);
        float value;
        std::istringstream iss(value_str);
        
         // Check point: isValidValue()
         
        iss >> value;
        if (iss.fail()) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }
        
        std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
        if (it == _db.end() || it->first != date) {
            if (it == _db.begin()) {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            --it;
        }
        float rate = it->second;
        float result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
}

const char* BitcoinExchange::CannotOpenFileException::what() const throw() {
    return "Cannot Open File";
}

const char* BitcoinExchange::MalformedLineException::what() const throw() {
    return "Malformed line";
}