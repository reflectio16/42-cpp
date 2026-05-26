/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:16:07 by meelma            #+#    #+#             */
/*   Updated: 2026/05/25 12:33:47 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *arr, const int len, F func) {
    
    for (int i = 0; i < len; i++) {
        func(arr[i]);
    }
}

#endif