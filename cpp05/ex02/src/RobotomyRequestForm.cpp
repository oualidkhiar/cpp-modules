#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    this->checkExecution(executor);
    std::cout << "Bzzzz... drilling noises..." << std::endl;
    if (rand() % 2) {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Failed to robotomize " << this->target << "." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& obj) {
    os << obj.getName() << ", form grade to execute is " <<
    obj.getGradeExecute() << ", form grade to sign is " << 
    obj.getGradetoSign();
    return os;
}

