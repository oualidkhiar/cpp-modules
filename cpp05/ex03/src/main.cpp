

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;

    AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
    AForm* form4 = someRandomIntern.makeForm("unknown form", "test");

    Bureaucrat boss("Boss", 1);

    std::cout << "\n--- Testing execution ---\n" << std::endl;

    if (form1)
    {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }

    if (form2)
    {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    if (form3)
    {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    if (form4)
        delete form4;

    return 0;
}