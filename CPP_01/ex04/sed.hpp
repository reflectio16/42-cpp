/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:54:37 by meelma            #+#    #+#             */
/*   Updated: 2026/01/26 11:05:57 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
#define SED_H

#include <iostream>
#include <fstream>
#include <string>

std::string readFile(std::string fileName);
void replaceText(std::string fileName, std::string s1, std::string s2);

#endif