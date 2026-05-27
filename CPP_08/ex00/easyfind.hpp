/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:52:31 by meelma            #+#    #+#             */
/*   Updated: 2026/05/27 11:22:59 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() { return "Value not found in container"; }
};

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"

#endif