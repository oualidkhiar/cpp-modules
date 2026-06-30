#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try {
            Rpn rp;
            int res = rp.execute(av[1]);
            std::cout << res << std::endl;
        }
        catch(std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    else {
        if (ac == 1) 
        {
            std::cerr << "Error: Please provide a Polish notation expression as an argument." << std::endl;
        }
        else {
            std::cerr << "Error: Too many arguments provided. Please enclose your entire RPN expression inside double quotes." << std::endl;
        }
    }
}