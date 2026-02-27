
#include "../includes/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("Bob", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "execution can continue from here " << std::endl;
}
