/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:07:22 by meelma            #+#    #+#             */
/*   Updated: 2026/06/02 18:47:57 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

class BitcoinExchange {
  
    private:
        std::map<std::string, float> _db;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& path);  // reads data.csv
        void processInput(const std::string& path);  // reads the arg file, prints
        
        class CannotOpenFileException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class MalformedLineException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        
};

#endif