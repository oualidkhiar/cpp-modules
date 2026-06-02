#include "../includes/Span.hpp"

Span::Span(size_t N): N(N){}


Span::Span(const Span& other): N(other.N), v(other.v) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->N = other.N;
        this->v = other.v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int val) {
    if (v.size() >= N) {
        throw containerFullException();
    }
    v.push_back(val);
}

int Span::shortestSpan( void ) {

    if (v.size() <= 1) {
        throw NoSpanFoundException();
    }

    std::vector<int> copy(v);

    std::sort(copy.begin(), copy.end());

    int smallest = copy[1] - copy[0];

    for (size_t i = 1; i < copy.size() - 1; i++) {
        int current = copy[i + 1] - copy[i];
        if (smallest > current) {
            smallest = current;
        }
    }
    return smallest;
}

int Span::longestSpan( void ) {

    if (v.size() <= 1) {
        throw NoSpanFoundException();
    }

    std::vector<int> copy(v);

    std::sort(copy.begin(), copy.end());

    return copy[(copy.size() - 1)] - copy[0];
}

const char *Span::containerFullException::what() const throw() {
    return "Container is full of elements.";
}

const char *Span::NoSpanFoundException::what() const throw() {
    return "Not enough elements to compute a span.";
}