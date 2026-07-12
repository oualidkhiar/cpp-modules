#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
    try {
        ParsedArgs args(ac - 1);
        args.parse_args(av + 1);
        PmergeMe p(args);
        p.sort_using_vector();
        p.sort_using_deque();
 
        std::cout << "before: ";
        p.print_original_input();
        std::cout << "after: ";
        p.print_sorted_vector();
        std::cout << "Time to process a range of " << args.get_size() << " elements with std::vector<> : " << p.get_vector_time() << " us." << std::endl;

        std::cout << "before: ";
        p.print_original_input();
        std::cout << "after: ";
        p.print_sorted_deque();
        std::cout << "Time to process a range of " << args.get_size() << " elements with std::deque<> : " << p.get_deque_time() << " us." << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what();
    }
}