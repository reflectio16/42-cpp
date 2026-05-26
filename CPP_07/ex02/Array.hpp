/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:11:23 by meelma            #+#    #+#             */
/*   Updated: 2026/05/26 13:26:21 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
    private:
        T *_data;
        unsigned int _size;
    
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        Array &operator=(Array const &other);
        ~Array();

        T   &operator[](unsigned int i);
        unsigned int size() const;
    
};

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other) : _data(new T[other._size]()), _size(other._size) {
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _data = new T[_size]();
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw std::exception();
    return _data[i];
}



template <typename T>
Array<T>::~Array() { delete[] _data; }

template <typename T>
unsigned int Array<T>::size() const { return _size; }




#endif