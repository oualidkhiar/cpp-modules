

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    std::cout << "===== TEST 1: Execute unsigned form =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("home");

        bob.executeForm(form); // should FAIL (not signed)
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Sign and execute =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("garden");

        bob.signForm(form);       // should succeed
        bob.executeForm(form);    // should succeed

        std::cout << "Check file: garden_shrubbery" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Low grade execution =====" << std::endl;
    try {
        Bureaucrat low("LowGuy", 150);
        ShrubberyCreationForm form("fail");

        low.signForm(form);       // should FAIL (grade too low)
        low.executeForm(form);    // should not even reach here
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Copy constructor =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm original("copy_test");

        bob.signForm(original);

        ShrubberyCreationForm copy(original);

        bob.executeForm(copy); // should work if copy is correct

        std::cout << "Check file: copy_test_shrubbery" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: Assignment operator =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm a("A");
        ShrubberyCreationForm b("B");

        bob.signForm(a);

        b = a; // assign

        bob.executeForm(b); // should execute with target "A"

        std::cout << "Check file: A_shrubbery" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}