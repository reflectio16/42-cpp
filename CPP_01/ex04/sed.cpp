/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:02:57 by meelma            #+#    #+#             */
/*   Updated: 2026/01/21 16:08:56 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string readFile(std::string fileName) {
    
    std::string line;
    std::string inputText;

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cout << "Cannot open file: " << fileName << std::endl;
        return "";
    }
    
    while (getline(inputFile, line)) {
        inputText += line + "\n";
    }
    
    if (inputText.empty()) {
        std::cout << "Nothing to read! Empty file" << std::endl;
        return "";
    }

    inputFile.close();
    return inputText;
}

void replaceText(std::string fileName, std::string s1, std::string s2) {
    
    if (s1.empty()) {
        std::cout << "Nothing to search! Search string is empty" << std::endl;
        return ;
    }

    std::string inputText;
    std::string result;
    size_t pos = 0;
    size_t found;

    inputText = readFile(fileName);
    if (inputText.empty())
        return ;
    
    while ((found = inputText.find(s1, pos)) != std::string::npos) {
        result += inputText.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += inputText.substr(pos);
    
    std::ofstream ofile;
    ofile.open(fileName + ".replace");
    ofile << result;
    ofile.close();
}


    



