/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:47:40 by meelma            #+#    #+#             */
/*   Updated: 2026/01/13 13:47:41 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av) {

    for (int i = 1; i < ac; i++) {

        for (int j = 0; av[i][j]; j++) {

            std::cout << (char)toupper(av[i][j]);
        }
    }
    std::cout << std::endl;
    return (0);
}