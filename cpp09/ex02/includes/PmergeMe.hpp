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

        ParsedArgs(const int& size);

        ParsedArgs(const ParsedArgs& other);

        ParsedArgs& operator=(const ParsedArgs& other) ;

        ~ParsedArgs();

        size_t operator[](int index) const ;

        void parse_args(char **args);
        void validateNumber(char *number);

        size_t get_size() const;
        void print_elements() const;

        std::vector<size_t> get_elements();
};


struct pairNode {
    size_t _value;
    std::vector<pairNode> _pairs;

    pairNode(size_t value, pairNode pair);
    pairNode(const pairNode& other);
    pairNode& operator=(const pairNode& other);
    pairNode(size_t value);
    pairNode();


    void insertNewLocalPair(const pairNode& localSmall);

    pairNode getSmallForthisLocalCall();
};

class PmergeMe {
    private:

        ParsedArgs& _parsed_elements;
        std::vector<size_t> _sorted_vector;
        std::deque<size_t> _sorted_deque;
        double         _vector_time_to_sort;
        double         _deque_time_to_sort;


        // vector functions
        std::vector<size_t> jacobsthalSequence(size_t upTo);
        std::vector<size_t> jacobsthalInsertOrder(size_t pendingCount);
    
        std::vector<pairNode> insertIntoMainShain(std::vector<pairNode>& larges, bool& has_stragle, pairNode stragle);
        
        std::vector<pairNode> getRecursiveLevelLarges(std::vector<pairNode>& input);
        
        std::vector<pairNode> fordJohnsonVector(std::vector<pairNode> input, int level);
        
        std::vector<size_t> finalInsertion_level0(std::vector<pairNode>& larges, bool& has_stragle, size_t stragle);
        
        std::vector<pairNode> getFirstLevelLarges(std::vector<size_t>& input);
        
        // deque functions
        std::deque<size_t> deq_jacobsthalSequence(size_t upTo);
        std::deque<size_t> deq_jacobsthalInsertOrder(size_t pendingCount);

        std::deque<pairNode> deq_insertIntoMainShain(std::deque<pairNode>& larges, bool& has_stragle, pairNode stragle);
        
        std::deque<pairNode> deq_getRecursiveLevelLarges(std::deque<pairNode>& input);
        
        std::deque<pairNode> fordJohnsonDeque(std::deque<pairNode> input, int level);
        
        std::deque<size_t> deq_finalInsertion_level0(std::deque<pairNode>& larges, bool& has_stragle, size_t stragle);
        
        std::deque<pairNode> deq_getFirstLevelLarges(std::deque<size_t>& input);

    public:
        
        PmergeMe(ParsedArgs& p);
        PmergeMe(const PmergeMe& other);    
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void sort_using_vector();
        void sort_using_deque();

        // ----------------getters and printers----------------

        std::vector<size_t>&    get_sorted_vector();
        std::deque<size_t>&     get_sorted_deque() ;
        double                  get_vector_time() const;
        double                  get_deque_time() const;

        void print_sorted_vector();
        void print_sorted_deque();
        void print_original_input();
};


bool compareByValue(const pairNode& node, size_t value);

#endif