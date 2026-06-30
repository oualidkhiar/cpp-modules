
#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2) {
        BitcoinExchange btc;
        btc.load_data_base();
        // btc.print_data_base();
        btc.applyRate(av[1]);
    } else {
        std::cerr << "Error: could not open file." << std::endl;
    }

}