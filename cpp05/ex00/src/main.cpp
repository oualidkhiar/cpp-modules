
#include "../includes/Bureaucrat.hpp"

int main() {
    Bureaucrat a("walid", 1);
    Bureaucrat b("dhdj", 252);

    a.incrementGrade();

    std::cout << a << b;

}