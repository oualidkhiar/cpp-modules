
#include "../includes/PmergeMe.hpp"


int main(int ac, char **av)
{
    try {
        if (ac > 1) {
            ParsedArgs args(ac - 1);
            args.parse_args(av+1);
            // args.print_vect();
            // std::cout << args[120] << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}