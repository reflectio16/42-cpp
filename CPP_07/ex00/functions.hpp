/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:51:33 by meelma            #+#    #+#             */
/*   Updated: 2026/05/25 12:12:02 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template <typename T>
void swap(T &a, T &b) {
    
    T tmp = a;
    a = b;
    b = tmp; 
}

template <typename T>
T const &min(T const &a, T const &b) {
    
    if (a < b)
        return a;
    return b;  
           
}

template <typename T>
T const &max(T const &a, T const &b) {
    
    if (a > b)
        return a;
    return b;
}


#endif