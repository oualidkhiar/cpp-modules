#include <iostream>
#include <vector>
#include <algorithm>
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

struct pairNode {
    size_t _value;
    std::vector<size_t> _pair_indeces;

    pairNode(size_t value, size_t _pair_index) {
        _value = value;
        _pair_indeces.push_back(_pair_index);
    }

    pairNode(const pairNode& other) {
        _value = other._value;
        _pair_indeces = other._pair_indeces;
    }

    pairNode& operator=(const pairNode& other) {
        if (this != &other) {
            _value = other._value;
            _pair_indeces = other._pair_indeces;
        }
        return *this;
    }

    pairNode() {}

};

bool compareByValue(const pairNode& node, size_t value) {
    return node._value < value;
}

std::vector<pairNode> fordJohnsonVector(std::vector<pairNode> input, int level)
{
    if (input.size() <= 1) {
        return input;
    }

    std::vector<pairNode> larges;
    std::vector<pairNode> smalles;

    bool has_stragle = (input.size() % 2);
    pairNode stragle;
    if (has_stragle) {
        stragle = input.back();
        input.pop_back();
    }

    size_t i = 0;
    while (i + 1 < input.size())
    {
        if (input[i]._value > input[i + 1]._value)
        {
            smalles.push_back(input[i + 1]);
            input[i]._pair_indeces.push_back(smalles.size() - 1);
            larges.push_back(input[i]);
        }
        else
        {
            smalles.push_back(input[i]);
            input[i + 1]._pair_indeces.push_back(smalles.size() - 1);
            larges.push_back(input[i + 1]);
        }
        i += 2;
    }

    std::vector<pairNode> sortedlarges = fordJohnsonVector(larges, level + 1);

    std::vector<pairNode> mainShain;

    mainShain.push_back(smalles[sortedlarges[0]._pair_indeces.back()]);

    std::vector<size_t> pairs_indeces;

    for (size_t k = 0; k < sortedlarges.size(); k++)
    {
        pairs_indeces.push_back(sortedlarges[k]._pair_indeces.back());
        sortedlarges[k]._pair_indeces.pop_back();
        mainShain.push_back(sortedlarges[k]);
    }

    for (size_t k = 1; k < smalles.size(); k++)
    {
        pairNode toInsert = smalles[pairs_indeces[k]];

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

int main() {


    std::vector<size_t> input = {10, 5, 2, 8, 17, 3, 13, 4, 16}; // 10 8 17 13
    std::vector<pairNode> larges;
    std::vector<size_t> smalles;
    size_t i = 0;

    while (i + 1 < input.size())
    {
        if (input[i] > input[i + 1])
        {
            smalles.push_back(input[i + 1]);
            larges.push_back(pairNode(input[i], smalles.size() - 1));
        }
        else 
        {
            smalles.push_back(input[i]);
            larges.push_back(pairNode(input[i + 1], smalles.size() - 1));
        }
        i += 2;
    }

    std::vector<pairNode> sortedlarges = fordJohnsonVector(larges ,0);

    // std::cout << "---------- "<< "level " << " ------------------" << "\n";
    // for (int i = 0; i < sortedlarges.size(); i++)
    // {
    //     std::cout << "value " << sortedlarges[i]._value << "  --- ";
    //     std::cout << "its pairs indeces:";
    //     for (int j = 0; j < sortedlarges[i]._pair_indeces.size(); j++ ){
    //          std::cout << " ";
    //          std::cout << sortedlarges[i]._pair_indeces[j];
    //     }
    //     std::cout << std::endl;
    // }



    std::vector<size_t> mainShain;
    mainShain.push_back(smalles[sortedlarges[0]._pair_indeces.back()]);

    sortedlarges[0]._pair_indeces.pop_back();

    for (size_t k = 0; k < sortedlarges.size(); k++)
        mainShain.push_back(sortedlarges[k]._value);

    for (size_t k = 1; k < smalles.size(); k++) {
        size_t toInsert = smalles[sortedlarges[k]._pair_indeces.back()];
        sortedlarges[k]._pair_indeces.back();

        auto pos = std::lower_bound(mainShain.begin(), mainShain.end(), toInsert);

        mainShain.insert(pos, toInsert);

    }


    for (size_t i = 0; i < mainShain.size(); i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << mainShain[i];
    }



    // for (size_t i = 0; i < sortedlarges.size(); i++) {
    //     if (i > 0) {
    //         std::cout << " ";
    //     }
    //     std::cout << sortedlarges[i]._value;
    // }


    std::cout << std::endl;
}
