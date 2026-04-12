/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:25:01 by meelma            #+#    #+#             */
/*   Updated: 2026/01/21 16:05:51 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int ac, char **av) {
    
    if (ac != 4) {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    
    replaceText(av[1], av[2], av[3]);

    return 0;
}