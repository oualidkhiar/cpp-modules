#include "../includes/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { (void)other; }

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

long long Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<long long>(ptr);
}

Data *Serializer::deserialize(long long raw)
{
    return reinterpret_cast<Data *>(raw);
}
