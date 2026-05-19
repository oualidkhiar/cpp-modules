#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

template <typename T>
class Array {
    private:

        T *_array;
        size_t n;

    public:

        Array(): _array(NULL), n(0) {}

        Array(size_t n)
        {
            this->n = n;
            _array = new T[n];
            if (!_array) {
                n = 0;
                return ;
            }
            for (size_t i = 0; i < n; i++) {
                _array[i] = 0;
            }
        }

        Array(const Array& other)
        {
            this->n = other.n;
            this->_array = new T[n];
            if (!(this->_array)) {
                n = 0;
                return ;
            }
            for (size_t i = 0; i < n; i++) {
                this->_array[i] = other._array[i];
            }
        }

        Array& operator=(const Array& other)
        {
            if (this != &other) {
                if (this->_array) {
                    delete _array;
                }
                this->n = other.n;
                this->_array = new T[n];
                if (!(this->_array)) {
                    this->n = 0;
                    return *this;
                }
                for (size_t i = 0; i < n; i++) {
                    this->_array[i] = other._array[i];
                }
            }
            return *this;
        }

        T& operator[](size_t i) const {
            if (i >= n) {
                throw std::out_of_range("Index out of range");
            }
            return _array[i];
        }

        size_t size() const {
            return this->n;
        }

        ~Array() {
            if (_array) {
                delete[] _array;
            }
        }
};



#endif