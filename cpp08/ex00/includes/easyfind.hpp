#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
    public:
        const char *what() const throw() {
            return "Value not found";
        }
};

template <typename T>
typename T::iterator easyfind(T& contianer, int val)
{
    typename T::iterator it;
    
    it = std::find(contianer.begin(), contianer.end(), val);
    if (it == contianer.end()) {
        throw NotFoundException();
    }
    return it;
}


#endif