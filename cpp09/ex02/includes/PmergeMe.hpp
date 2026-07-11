#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>

class ParsedArgs {
    private:

        std::vector<size_t> _elements;

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

        std::vector<int> get_elements() {
            return _elements;
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
        std::vector<size_t> _sorted_vector;
        std::deque<size_t> _sorted_deque;
        double         _vector_time_to_sort;
        double         _deque_time_to_sort;


        template <typename T>
        std::vector<Pair> create_pairs(T& used_container)
        {
            std::vector<Pair> pairs;
            size_t i = 0;

            while (i + 1 < used_container.size())
            {
                Pair p(used_container[i], used_container[i + 1]);
                pairs.push_back(p);
                i += 2;
            }
            return pairs;
        }
        
        std::vector<size_t> fordJohnsonVector(std::vector<Pair> pairs, std::vector<size_t>& input, bool is_firstCall)
        {
            if (pairs.size() <= 1 and !is_firstCall) {
                return pairs;
            }
            
            std::vector<Pair> pairs = create_pairs(input);

            // size_t straggler;
            // bool has_straggler = false;

            // if (input.size() % 2 != 0) {
            //     has_straggler = true;
            //     straggler = input[input.size() - 1];
            // }

            // std::vector<size_t> larges;
            // std::vector<size_t> smalles;
            // std::vector<size_t> small_index_per_large;

            larges.reserve(input.size() / 2);

            for (size_t i = 0; i < (input.size() / 2); i++) {
                input.push_back(pairs[i].large);
                // smalles.push_back(pairs[i].small);
                // small_index_per_large.push_back(i);
            }

            std::vector<Pair> sortedLarges_with_thier_small_pairs = fordJohnsonVector(pairs, input, false);

            std::vector<size_t> mainShain;

            // insert large numbers into mainShain
            for (size_t i = 0; i < sortedLarges_with_thier_small_pairs.size(); i++) {
                mainShain.push_back(sortedLarges_with_thier_small_pairs[i].large);
            }

            // insert small numbers into mainShain
            for (size_t i = 0; i < sortedLarges_with_thier_small_pairs.size(); i++) {
                auto pos = std::lower_bound(mainShain.begin(); mainShain.end(), sortedLarges_with_thier_small_pairs[i].small);

                mainShain.insert(pos, sortedLarges_with_thier_small_pairs[i].small);
            }
            return create_pairs(mainShain);
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
            // clock_t start = clock();

            std::vector<size_t> input = _parsed_elements.get_elements();
            // std::vector<Pair> pairs = create_pairs(input);

            std::vector<Pair> Sortedpairs = fordJohnsonVector({}, input, true);
            int i = 0;
            while (i < Sortedpairs.size())
            {
                if (i > 0)
                    std::cout << " ";
                std::cout << Sortedpairs[i];
            }
            std::cout << std::endl;
            // clock_t end = clock();
            // this->_vector_time_to_sort = static_cast<double>(end - start);

        }


        // ----------------getters and printers----------------
        std::vector<size_t>& get_sorted_vector() {return _sorted_vector;}
        std::deque<size_t>& get_sorted_deque() {return _sorted_deque;}
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