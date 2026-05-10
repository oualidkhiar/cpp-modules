#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdint.h>

struct Data
{
    std::string name;
    int age;
};


class Serializer
{
public:
    Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

    static long long serialize(Data *ptr);
    static Data *deserialize(long long raw);
};

#endif