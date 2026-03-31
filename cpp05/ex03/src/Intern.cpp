#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    if (formName == "shrubbery creation") {
        return new ShrubberyCreationForm(target);
    } else if (formName == "robotomy request") {
        return new RobotomyRequestForm(target);
    } else if (formName == "presidential pardon") {
        return new PresidentialPardonForm(target);
    } else {
        std::cerr << "Error: Unknown form name '" << formName << "'." << std::endl;
        return NULL;
    }
}

