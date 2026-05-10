#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    static void convert(const std::string &literal);
private:
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);
    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

    static float toFloat(const std::string &literal);
    static double toDouble(const std::string &literal);
    static int toInt(const std::string &literal);
};


#endif