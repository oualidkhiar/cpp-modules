#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>


class Span {
    private:

        size_t N;
        std::vector<int> v;

    public:

        Span(size_t N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int val);

        int shortestSpan( void );
        int longestSpan( void );

        class containerFullException : public std::exception {
            public:
                const char *what() const throw();
        };

        class NoSpanFoundException: public std::exception {
            public:
                const char *what() const throw();
        };

        template <typename It>
        void addNumber(It begin, It end) {
            if (static_cast<size_t>(std::distance(begin, end)) > N) {
                throw containerFullException();
            }
            v.insert(v.end(), begin, end);
        }
};

#endif