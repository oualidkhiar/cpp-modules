#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade) {
    std::cout << "constructor called for " << this->name << std::endl;
    GradeTooHighException();
    GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {
    std::cout << "copy constructor called for " << this->name << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "destructor called for " << this->name << std::endl;
}

const std::string Bureaucrat::getName() const {return this->name;}

int Bureaucrat::getGrade() const {return grade;}

void Bureaucrat::incrementGrade( void ) {
    this->grade -= 1;
    GradeTooHighException();
}

void Bureaucrat::decrementGrade( void ) {
    this->grade += 1;
    GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}

void Bureaucrat::GradeTooHighException()
{
    try {
        if (this->grade < HIGHEST_GRADE){
            throw // grade too high
        }
    }
    catch (exception& e) {

    }
}

void Bureaucrat::GradeTooLowException()
{
    try {
        if (this->grade > LOWEST_GRADE) {
            throw // grade too low
        }
    }
    catch (exception& e) {
        
    }
}