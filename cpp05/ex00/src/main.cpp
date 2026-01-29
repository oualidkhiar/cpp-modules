
#include "../includes/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("Bob", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "execution can continue from here " << std::endl;
}
