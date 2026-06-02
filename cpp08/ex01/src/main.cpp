#include "../includes/Span.hpp"
#include <list>

int main()
{
    std::cout << "===== BASIC TEST =====" << std::endl;

    Span sp(5);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== RANGE TEST (VECTOR) =====" << std::endl;

    Span sp2(10);
    std::vector<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(i * 3);

    try
    {
        sp2.addNumber(v.begin(), v.end());
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== RANGE TEST (LIST) =====" << std::endl;

    Span sp3(6);
    std::list<int> l;

    l.push_back(100);
    l.push_back(50);
    l.push_back(300);
    l.push_back(10);
    l.push_back(200);
    l.push_back(5);

    try
    {
        sp3.addNumber(l.begin(), l.end());
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

    std::cout << "\n===== ERROR TEST =====" << std::endl;

    Span sp4(1);
    sp4.addNumber(10);

    try
    {
        std::cout << sp4.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    return 0;
}