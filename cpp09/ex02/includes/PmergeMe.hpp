#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <deque>

class ParsedArgs {
    private:

        std::vector<unsigned int> _elements;

    public:

        ParsedArgs(const int& size): _elements(size) {}

        ParsedArgs(const ParsedArgs& other): _elements(other._elements) {}

        ParsedArgs& operator=(const ParsedArgs& other) {
            if (this != &other) { 
                this->_elements.operator=(other._elements);
            }
            return *this;
        }

        ~ParsedArgs() {}

        int operator[](int index) const {
            if (index < 0 || index >= get_size()) {
                throw std::out_of_range("Index out of range");
            }
            return _elements[index];
        }

        void parse_args(char **args) {
            size_t i = 0;

            while (i < _elements.size())
            {
                int currentItem;
                std::istringstream stream(args[i]);

                if (stream >> currentItem)
                {
                    if (currentItem < 0)
                    {
                        throw std::runtime_error("only positive numbers are allowed");
                    }
                    else {
                        _elements[i] = currentItem;
                    }
                }
                else {
                    throw std::runtime_error("only positive numbers are allowed");
                }
                i++;
            }
        }

        size_t get_size() const {
            return this->_elements.size();
        }
        
        void print_elements() {
            for (size_t i = 0; i < get_size(); i++) {
                std::cout << _elements[i] << " ";
            }
            std::cout << std::endl;
        }
};


class PmergeMe {
    private:

        ParsedArgs& _parsed_elements;

    public:

        PmergeMe(ParsedArgs& p) : _parsed_elements(p) {}

        PmergeMe(const PmergeMe& other) : _parsed_elements(other._parsed_elements) {}
     
        PmergeMe& operator=(const PmergeMe& other) {
            if (this != &other) {
                this->_parsed_elements = other._parsed_elements;
            }
            return *this;
        }

        ~PmergeMe() {}
};



#endif