#include "../includes/easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Vector found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Vector error: " << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(l, 2);
        std::cout << "List found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "List error: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(v, 999);
        std::cout << "Should not print: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Not found test: " << e.what() << std::endl;
    }

    return 0;
}