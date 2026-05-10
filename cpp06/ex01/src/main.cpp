#include "../includes/Serializer.hpp"

int main()
{
    Data data = {"Alice", 30};

    long long raw = Serializer::serialize(&data);
    std::cout << "Serialized data: " << raw << std::endl;

    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data: Name = " << deserializedData->name
              << ", Age = " << deserializedData->age << std::endl;

    return 0;
}