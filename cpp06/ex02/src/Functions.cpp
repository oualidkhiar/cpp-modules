#include "../includes/Functions.hpp"

Base* CreateA(void)
{
    return new A();
}

Base* CreateB(void)
{
    return new B();
}
Base* CreateC(void)
{
    return new C();
}

Base* generate(void)
{
    int random = rand() % 3;

    CreateFunc createFuncs[3] = {CreateA, CreateB, CreateC};
    return createFuncs[random]();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a; // To avoid unused variable warning
    }
    catch (std::bad_cast&)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)b; // To avoid unused variable warning
        }
        catch (std::bad_cast&)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)c; // To avoid unused variable warning
            }
            catch (std::bad_cast&)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}