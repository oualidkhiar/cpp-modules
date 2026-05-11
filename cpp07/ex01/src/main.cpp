#include "../includes/iter.hpp"

void printInt(int &i)
{
    std::cout << i << std::endl;
}
void printFloat(float &f){
    std::cout << f << std::endl;
}

void printString(std::string &s){
    std::cout << s << std::endl;
}

void printConstInt(const int &i)
{
    std::cout << i << std::endl;
}
void printConstFloat(const float &f){
    std::cout << f << std::endl;
}

void printConstString(const std::string &s){
    std::cout << s << std::endl;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::string stringArray[] = {"Hello", "World", "C++", "Templates", "Iter"};

    iter(intArray, 5, printInt);
    iter(floatArray, 5, printFloat);
    iter(stringArray, 5, printString);
    iter(intArray, 5, printConstInt);
    iter(floatArray, 5, printConstFloat);
    iter(stringArray, 5, printConstString);


    return 0;
}