#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(ParsedArgs& p) : _parsed_elements(p) ,_vector_time_to_sort(0.0), _deque_time_to_sort(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : _parsed_elements(other._parsed_elements) {}
     
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_parsed_elements = other._parsed_elements;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// ----------------getters and printers----------------

std::vector<size_t>& PmergeMe::get_sorted_vector() {return _sorted_vector;}
std::deque<size_t>& PmergeMe::get_sorted_deque() {return _sorted_deque;}
double PmergeMe::get_vector_time() const {return _vector_time_to_sort;}
double PmergeMe::get_deque_time() const {return _deque_time_to_sort;}

void PmergeMe::print_sorted_vector() {
    for (size_t i = 0; i < _sorted_vector.size(); i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << _sorted_vector[i];
    }
    std::cout << std::endl;
}

void PmergeMe::print_sorted_deque() {
    for (size_t i = 0; i < _sorted_deque.size(); i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << _sorted_deque[i];
    }
    std::cout << std::endl;
}

void PmergeMe::print_original_input() {this->_parsed_elements.print_elements();};

// ---------------------------------------vector algo implementation---------------------------------

std::vector<size_t> PmergeMe::jacobsthalSequence(size_t upTo)
{
    std::vector<size_t> v;
    v.push_back(0);
    v.push_back(1);
    while (v.back() < upTo)
        v.push_back(v[v.size() - 1] + 2 * v[v.size() - 2]);
    return v;
}

std::vector<size_t> PmergeMe::jacobsthalInsertOrder(size_t pendingCount)
{
    std::vector<size_t> raw = jacobsthalSequence(pendingCount + 1);

    std::vector<bool> is_jachobstal(raw.back() + 1, false);

    std::vector<size_t> order;


    for (size_t i = 0; i < raw.size(); i++)
    {
        size_t r = raw[i];
        is_jachobstal[r] = true;
    }

    for (size_t i = 3; i < raw.size(); i++) 
    {
        size_t start = raw[i] - 1;

        while (!is_jachobstal[start]) {
            if (start > 0 && start <= pendingCount) {
                order.push_back(start);
            }
            start--;
        }
        if (start > 0 && start <= pendingCount) {
            order.push_back(start);
        }
    }
    return order;
}


std::vector<pairNode> PmergeMe::insertIntoMainShain(std::vector<pairNode>& larges, bool& has_stragle, pairNode stragle)
{
    std::vector<pairNode> mainShain;

    mainShain.push_back(larges[0]._pairs.back());

    std::vector<pairNode> smalls;

    for (size_t k = 0; k < larges.size(); k++)
    {
        smalls.push_back(larges[k].getSmallForthisLocalCall());
        mainShain.push_back(larges[k]);
    }

    std::vector<size_t> order_of_insertion = jacobsthalInsertOrder(smalls.size() - 1);

    for (size_t o = 0; o < order_of_insertion.size(); o++)
    {
        pairNode toInsert = smalls[order_of_insertion[o]];

        std::vector<pairNode>::iterator pos = 
        std::lower_bound(mainShain.begin(), mainShain.end(), toInsert._value, compareByValue);

        mainShain.insert(pos, toInsert);
    }

    if (has_stragle)
    {
        std::vector<pairNode>::iterator pos = 
        std::lower_bound(mainShain.begin(), mainShain.end(), stragle._value, compareByValue);

        mainShain.insert(pos, stragle);
    }
    return mainShain;
}

std::vector<pairNode> PmergeMe::getRecursiveLevelLarges(std::vector<pairNode>& input)
{
    std::vector<pairNode> larges;

    size_t i = 0;

    while (i + 1 < input.size())
    {
        if (input[i]._value > input[i + 1]._value)
        {
            pairNode large = input[i];

            large.insertNewLocalPair(input[i + 1]);

            larges.push_back(large);
        }
        else
        {
            pairNode large = input[i + 1];

            large.insertNewLocalPair(input[i]);

            larges.push_back(large);
        }
        i += 2;
    }
    return larges;
}

std::vector<pairNode> PmergeMe::fordJohnsonVector(std::vector<pairNode> input, int level)
{
    if (input.size() <= 1) {
        return input;
    }

    std::vector<pairNode> larges;

    bool has_stragle = (input.size() % 2);
    pairNode stragle;
    if (has_stragle) {
        stragle = input.back();
        input.pop_back();
    }

    std::vector<pairNode> sortedlarges = fordJohnsonVector(getRecursiveLevelLarges(input), level + 1);

    return insertIntoMainShain(sortedlarges, has_stragle, stragle);
}

std::vector<size_t> PmergeMe::finalInsertion_level0(std::vector<pairNode>& larges, bool& has_stragle, size_t stragle)
{
    std::vector<size_t> mainShain;
    mainShain.push_back(larges[0]._pairs.back()._value);

    for (size_t k = 0; k < larges.size(); k++)
        mainShain.push_back(larges[k]._value);

    std::vector<size_t> order_of_insertion = jacobsthalInsertOrder(larges.size() - 1);

    for (size_t o = 0; o < order_of_insertion.size(); o++) {
        size_t toInsert = larges[order_of_insertion[o]]._pairs.back()._value;

        std::vector<size_t>::iterator pos = std::lower_bound(mainShain.begin(), mainShain.end(), toInsert);

        mainShain.insert(pos, toInsert);

    }

    if (has_stragle)
    {
        std::vector<size_t>::iterator pos = 
        std::lower_bound(mainShain.begin(), mainShain.end(), stragle);

        mainShain.insert(pos, stragle);
    }

    return mainShain;
}

std::vector<pairNode> PmergeMe::getFirstLevelLarges(std::vector<size_t>& input) 
{
    std::vector<pairNode> larges;
    size_t i = 0;

    while (i + 1 < input.size())
    {
        if (input[i] > input[i + 1])
        {
            pairNode smalls(input[i + 1]);
            larges.push_back(pairNode(input[i], smalls));
        }
        else 
        {
            pairNode smalls(input[i]);
            larges.push_back(pairNode(input[i + 1], smalls));
        }
        i += 2;
    }
    return larges;
}


void PmergeMe::sort_using_vector()
{
    clock_t start = clock();

    std::vector<size_t> input = _parsed_elements.get_elements();

    bool has_stragle = (input.size() % 2);

    size_t stragle;

    if (has_stragle) {
        stragle = input.back();
        input.pop_back();
    }

    if (_parsed_elements.get_size() == 1)
    {
        _sorted_vector.push_back(_parsed_elements[0]);
    }
    else 
    {
        std::vector<pairNode> sortedlarges = fordJohnsonVector(getFirstLevelLarges(input) ,0);

        _sorted_vector = finalInsertion_level0(sortedlarges, has_stragle, stragle);
    }

    clock_t end = clock();

    this->_vector_time_to_sort = (static_cast<double>(end - start) * 1000000.0) / CLOCKS_PER_SEC;
}


// ---------------------------------------deque algo implementation---------------------------------

std::deque<size_t> PmergeMe::deq_jacobsthalSequence(size_t upTo)
{
    std::deque<size_t> dq;
    dq.push_back(0);
    dq.push_back(1);
    while (dq.back() < upTo)
        dq.push_back(dq[dq.size() - 1] + 2 * dq[dq.size() - 2]);
    return dq;
}

std::deque<size_t> PmergeMe::deq_jacobsthalInsertOrder(size_t pendingCount)
{
    std::deque<size_t> raw = deq_jacobsthalSequence(pendingCount + 1);

    std::deque<bool> is_jachobstal(raw.back() + 1, false);

    std::deque<size_t> order;

    for (size_t i = 0; i < raw.size(); i++)
    {
        size_t r = raw[i]; 
        is_jachobstal[r] = true;
    }

    for (size_t i = 3; i < raw.size(); i++) 
    {
        size_t start = raw[i] - 1;

        while (!is_jachobstal[start]) {
            if (start > 0 && start <= pendingCount) {
                order.push_back(start);
            }
            start--;
        }
        if (start > 0 && start <= pendingCount) {
            order.push_back(start);
        }
    }
    return order;
}



std::deque<pairNode> PmergeMe::deq_insertIntoMainShain(std::deque<pairNode>& larges, bool& has_stragle, pairNode stragle)
{
    std::deque<pairNode> mainShain;

    mainShain.push_back(larges[0]._pairs.back());

    std::deque<pairNode> smalls;

    for (size_t k = 0; k < larges.size(); k++)
    {
        smalls.push_back(larges[k].getSmallForthisLocalCall());
        mainShain.push_back(larges[k]);
    }

    std::deque<size_t> order_of_insertion = deq_jacobsthalInsertOrder(smalls.size() - 1);

    for (size_t k = 0; k < order_of_insertion.size(); k++)
    {
        pairNode toInsert = smalls[order_of_insertion[k]];

        std::deque<pairNode>::iterator pos = 
        std::lower_bound(mainShain.begin(), mainShain.end(), toInsert._value, compareByValue);

        mainShain.insert(pos, toInsert);
    }

    if (has_stragle)
    {
        std::deque<pairNode>::iterator pos = 
        std::lower_bound(mainShain.begin(), mainShain.end(), stragle._value, compareByValue);

        mainShain.insert(pos, stragle);
    }
    return mainShain;
}

std::deque<pairNode> PmergeMe::deq_getRecursiveLevelLarges(std::deque<pairNode>& input)
{
    std::deque<pairNode> larges;

    size_t i = 0;

    while (i + 1 < input.size())
    {
        if (input[i]._value > input[i + 1]._value)
        {
            pairNode large = input[i];

            large.insertNewLocalPair(input[i + 1]);

            larges.push_back(large);
        }
        else
        {
            pairNode large = input[i + 1];

            large.insertNewLocalPair(input[i]);

            larges.push_back(large);
        }
        i += 2;
    }
    return larges;
}

std::deque<pairNode> PmergeMe::fordJohnsonDeque(std::deque<pairNode> input, int level)
{
    if (input.size() <= 1) {
        return input;
    }

    std::deque<pairNode> larges;

    bool has_stragle = (input.size() % 2);
    pairNode stragle;
    if (has_stragle) {
        stragle = input.back();
        input.pop_back();
    }

    std::deque<pairNode> sortedlarges = fordJohnsonDeque(deq_getRecursiveLevelLarges(input), level + 1);

    return deq_insertIntoMainShain(sortedlarges, has_stragle, stragle);
}


std::deque<size_t> PmergeMe::deq_finalInsertion_level0(std::deque<pairNode>& larges, bool& has_stragle, size_t stragle)
{
    std::deque<size_t> mainShain;
    mainShain.push_back(larges[0]._pairs.back()._value);

    for (size_t k = 0; k < larges.size(); k++)
        mainShain.push_back(larges[k]._value);

    std::deque<size_t> order_of_insertion = deq_jacobsthalInsertOrder(larges.size() - 1);

    for (size_t k = 0; k < order_of_insertion.size(); k++) {
        size_t toInsert = larges[order_of_insertion[k]]._pairs.back()._value;

        std::deque<size_t>::iterator pos = std::lower_bound(mainShain.begin(), mainShain.end(), toInsert);

        mainShain.insert(pos, toInsert);

    }

    if (has_stragle)
    {
        std::deque<size_t>::iterator pos = 
        std::lower_bound(mainShain.begin(), mainShain.end(), stragle);

        mainShain.insert(pos, stragle);
    }

    return mainShain;
}

std::deque<pairNode> PmergeMe::deq_getFirstLevelLarges(std::deque<size_t>& input)
{
    std::deque<pairNode> larges;
    size_t i = 0;

    while (i + 1 < input.size())
    {
        if (input[i] > input[i + 1])
        {
            pairNode smalls(input[i + 1]);
            larges.push_back(pairNode(input[i], smalls));
        }
        else 
        {
            pairNode smalls(input[i]);
            larges.push_back(pairNode(input[i + 1], smalls));
        }
        i += 2;
    }
    return larges;
}

void PmergeMe::sort_using_deque()
{
    clock_t start = clock();
    
    std::vector<size_t> toInsertIntoDeque = _parsed_elements.get_elements();

    std::deque<size_t> input(toInsertIntoDeque.begin(), toInsertIntoDeque.end());

    bool has_stragle = (input.size() % 2);

    size_t stragle;

    if (has_stragle) {
        stragle = input.back();
        input.pop_back();
    }

    if (_parsed_elements.get_size() == 1)
    {
        _sorted_deque.push_back(_parsed_elements[0]);
    }
    else 
    {
        std::deque<pairNode> sortedlarges = fordJohnsonDeque(deq_getFirstLevelLarges(input) ,0);

        _sorted_deque = deq_finalInsertion_level0(sortedlarges, has_stragle, stragle);
    }

    clock_t end = clock();

    this->_deque_time_to_sort = (static_cast<double>(end - start) * 1000000.0) / CLOCKS_PER_SEC;
}


bool compareByValue(const pairNode& node, size_t value) {
    return node._value < value;
}


// -------------------------------------------- data structure (pairNode) ------------------

pairNode::pairNode(size_t value, pairNode pair) {
    _value = value;
    _pairs.push_back(pair);
}

pairNode::pairNode(const pairNode& other) {
    _value = other._value;
    _pairs = other._pairs;
}

pairNode& pairNode::operator=(const pairNode& other) {
    if (this != &other) {
        _value = other._value;
        _pairs = other._pairs;
    }
    return *this;
}

pairNode::pairNode(size_t value): _value(value) {}

pairNode::pairNode() {}

void pairNode::insertNewLocalPair(const pairNode& localSmall)
{
    _pairs.push_back(localSmall);
}

pairNode pairNode::getSmallForthisLocalCall() {
    pairNode small = _pairs.back();
    _pairs.pop_back();
    return small;
}

// --------------------------------------------- parser -----------------------

ParsedArgs::ParsedArgs(const int& size): _elements(size) {}

ParsedArgs::ParsedArgs(const ParsedArgs& other): _elements(other._elements) {}

ParsedArgs& ParsedArgs::operator=(const ParsedArgs& other) {
    if (this != &other) { 
        this->_elements.operator=(other._elements);
    }
    return *this;
}

ParsedArgs::~ParsedArgs() {}

size_t ParsedArgs::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(get_size())) {
        throw std::out_of_range("Index out of range");
    }
    return _elements[index];
}

void ParsedArgs::validateNumber(char *number)
{
    size_t i = 0;

    if (number[i] == '+')
    {
        i++;
    }

    while (number[i])
    {
        if (number[i] > '9' || number[i] < '0') {
            throw std::runtime_error("only positive numbers are allowed");
        }
        i++;
    }
}

void ParsedArgs::parse_args(char **args) {
    if (_elements.size() == 0) {
        throw std::runtime_error("no elements found.");
    }
    size_t i = 0;

    while (i < _elements.size())
    {
        validateNumber(args[i]);
        size_t currentItem;
        std::istringstream stream(args[i]);

        if (stream >> currentItem)
        {
            _elements[i] = currentItem;
        }
        else {
            throw std::runtime_error("only positive numbers are allowed");
        }
        i++;
    }
}

size_t ParsedArgs::get_size() const {
    return this->_elements.size();
}
        
void ParsedArgs::print_elements() const {
    for (size_t i = 0; i < get_size(); i++) {
        std::cout << _elements[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<size_t> ParsedArgs::get_elements() {
    return _elements;
}