#include "../includes/Form.hpp"

int main()
{
    Bureaucrat B("firstB", 5);
    Form f("firstF", 0, 1);
    B.signForm(f);
}