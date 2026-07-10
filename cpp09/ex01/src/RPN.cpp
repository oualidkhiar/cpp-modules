#include "../includes/RPN.hpp"

int Rpn::execute(const std::string& s)
{
    std::stack<int> st;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (is_whitespace(s[i])) {
            continue ;
        }
        if (is_operator(s[i]))
        {
            if (st.size() < 2)
            {
                throw std::runtime_error("Syntax of Polish notation expression is incorrect");
            }
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            st.push(execute_op(s[i], left, right));
        }
        else {
            if (s[i] <= '9' and s[i] >= '0') {
                st.push(s[i] - '0');
            }
            else {
                throw std::runtime_error(std::string("unknown char ") + s[i]);
            }
            if (s[i + 1] != '\0' and !is_whitespace(s[+ 1 ])) {
                throw std::runtime_error("Syntax of Polish notation expression is incorrect");
            }
        }
    }
    return st.size() == 1 ? st.top() : throw std::runtime_error("Syntax of Polish notation expression is incorrect");
}


bool Rpn::is_operator(const char& c) {
    return c == '-' or c == '+' or c == '*' or c == '/';
}

bool Rpn::is_whitespace(const char& c) {
    return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

int Rpn::execute_op(const char& op, const int& left, const int& right) {

    if (op == '+') {
        return left + right;
    }
    else if (op == '-') {
        return left - right;
    }
    else if (op == '*') {
        return left * right;
    }
    return left/right;
}