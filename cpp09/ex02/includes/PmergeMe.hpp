#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>

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
        
        void print_elements() const {
            for (size_t i = 0; i < get_size(); i++) {
                std::cout << _elements[i] << " ";
            }
            std::cout << std::endl;
        }
};


typedef struct s_Pair {
    size_t small;
    size_t large;

    s_Pair(size_t a, size_t b) {
        small = a < b ? a : b;
        large = a < b ? b : a;
    }

    bool operator<(const Pair& other) const {
        return this->large < other.large;
    }

    bool operator>(const Pair& other) const {
        return this->large > other.large;
    }

    bool operator==(const Pair& other) const {
        return this->large == other.large; 
    }

} Pair;


class PmergeMe {
    private:

        ParsedArgs& _parsed_elements;
        std::vector<int> _sorted_vector;
        std::deque<int> _sorted_deque;
        double         _vector_time_to_sort;
        double         _deque_time_to_sort;

        size_t straggler;
        bool has_straggler;


        template <typename T>
        void create_pairs(T& used_container)
        {
            size_t i = 0;

            while (i < _parsed_elements.get_size())
            {
                if (i + 1 < _parsed_elements.get_size())
                {

                    Pair p(used_container[i], used_container[i + 1]);

                    used_container.push_back(p);
                }            
                i += 2;
            }

            if (_parsed_elements.get_size() % 2 == 0) {
                has_straggler = true;
                straggler = _parsed_elements[_parsed_elements.get_size() - 1];
            }
        }

        
        void fordJohnsonVector(std::vector<Pair>& pairs) {

        }


    public:

        PmergeMe(ParsedArgs& p) : _parsed_elements(p), _sorted_vector(p.get_size()), 
        _sorted_deque(p.get_size()),_vector_time_to_sort(0.0), _deque_time_to_sort(0.0), straggler(0), has_straggler(false) {}

        PmergeMe(const PmergeMe& other) : _parsed_elements(other._parsed_elements) {}
     
        PmergeMe& operator=(const PmergeMe& other) {
            if (this != &other) {
                this->_parsed_elements = other._parsed_elements;
            }
            return *this;
        }

        ~PmergeMe() {}

        void sort_using_vector() {
            clock_t start = clock();

            std::vector<Pair> vecPairs;
            vecPairs.reserve((_parsed_elements.get_size() / 2));
            create_pairs(vecPairs);

            void fordJohnsonVector(vecPairs);


            clock_t end = clock();
            this->_vector_time_to_sort = static_cast<double>(end - start);

        }


        // ----------------getters and printers----------------
        std::vector<int>& get_sorted_vector() {return _sorted_vector;}
        std::deque<int>& get_sorted_deque() {return _sorted_deque;}
        double get_vector_time() const {return _vector_time_to_sort;}
        double get_deque_time() const {return _deque_time_to_sort;}

        void print_sorted_vector() const {
            for (size_t i = 0; i < _sorted_vector.size(); i++) {
                std::cout << _sorted_vector[i];
            }
            std::cout << std::endl;
        }

        void print_sorted_deque() const {
            for (size_t i = 0; i < _sorted_deque.size(); i++) {
                std::cout << _sorted_deque[i];
            }
            std::cout << std::endl;
        }

        void print_original_input() const {this->_parsed_elements.print_elements()};
};



#endif