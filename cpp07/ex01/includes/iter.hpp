#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

// this one for non-const T
template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
    std::cout  << "called this one " << std::endl;
}
// this one for const T
template <typename T>
void iter(T *array, size_t length, void (*func)(const T &))
{
    for (size_t i = 0; i < length; i++) {   
        func(array[i]);
    }
    std::cout  << "called this one 2" << std::endl;
}

#endif