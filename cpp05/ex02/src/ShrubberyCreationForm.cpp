#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("shrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "deconstrictor called for name: " << this->getName() << " class ShrubberyCreationForm" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->target;
}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    this->checkExecution(executor);
    std::ofstream file((this->target + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }
    file << "       _-_" << std::endl;
    file << "   /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj) {
    os << obj.getName() << ", form grade to execute is " <<
    obj.getGradeExecute() << ", form grade to sign is " << 
    obj.getGradetoSign();
    return os;
}