#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <stack>

class Rpn {
    private:

    bool is_operator(const char& c);
    bool is_whitespace(const char& c);

    int execute_op(const char& op, const int& left, const int& right);

    public:

        int execute(const std::string& s);
};


#endif