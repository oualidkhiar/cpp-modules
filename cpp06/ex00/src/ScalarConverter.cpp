#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
    if (isChar(literal))
        printChar(literal[0]);
    else if (isInt(literal))
        printInt(ScalarConverter::toInt(literal));
    else if (isFloat(literal))
        printFloat(ScalarConverter::toFloat(literal));
    else if (isDouble(literal))
        printDouble(ScalarConverter::toDouble(literal));
    else
        std::cerr << "Error: Invalid literal" << std::endl;
}

bool ScalarConverter::isChar(const std::string &literal)
{
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal)
{
    size_t pos = 0;

    if (literal[pos] == '-' || literal[pos] == '+')
        pos++;

    for (; pos < literal.length(); pos++)
    {
        if (!std::isdigit(literal[pos]))
            return false;
    }

    return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    if (literal.empty())
        return false;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;

    bool dotSeen = false;
    bool digitSeen = false;
    size_t pos = 0;

    if (literal[pos] == '-' || literal[pos] == '+')
        pos++;

    if (literal[literal.length() - 1] != 'f' && literal[literal.length() - 1] != 'F') {
        return false;
    }

    for (; pos < literal.length() - 1; pos++)
    {
        if (std::isdigit(literal[pos]))
            digitSeen = true;
        else if (literal[pos] == '.' && !dotSeen)
            dotSeen = true;
        else
            return false;
    }

    return digitSeen && dotSeen;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    if (literal.empty())
        return false;

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;

    bool dotSeen = false;
    bool digitSeen = false;
    size_t pos = 0;

    if ((literal[pos] == '-' || literal[pos] == '+'))
        pos++;

    for (; pos < literal.length(); pos++)
    {
        if (std::isdigit(literal[pos]))
            digitSeen = true;
        else if (literal[pos] == '.' && !dotSeen)
            dotSeen = true;
        else
            return false;
    }

    return digitSeen && dotSeen;
}


float ScalarConverter::toFloat(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        return std::numeric_limits<float>::quiet_NaN();
    }
    else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
    {
        return std::numeric_limits<float>::infinity();
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        return -std::numeric_limits<float>::infinity();
    }

    float result;
    
    std::istringstream iss(literal);
    iss >> result;
    return result;
}

int ScalarConverter::toInt(const std::string &literal)
{
    return atoi(literal.c_str());
}

double ScalarConverter::toDouble(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        return std::numeric_limits<double>::quiet_NaN();
    }
    else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
    {
        return std::numeric_limits<double>::infinity();
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        return -std::numeric_limits<double>::infinity();
    }

    double result;
    std::istringstream iss(literal);
    iss >> result;
    return result;
}

void ScalarConverter::printChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printInt(int i)
{
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    if (std::isnan(f) || std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<int>(f)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<int>(d)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

