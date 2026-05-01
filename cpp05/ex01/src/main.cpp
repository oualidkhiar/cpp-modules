#include "../includes/Form.hpp"

int main()
{
    // could not  sign 
    try {
        Bureaucrat B("firstB", 5);
        Form f("firstF", 1, 1);
        B.signForm(f);
    }
    catch  (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    // it can sign 
    try {
        Bureaucrat B("firstB", 10);
        Form f("firstF", 12, 1);
        B.signForm(f);
    }
    catch  (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
}