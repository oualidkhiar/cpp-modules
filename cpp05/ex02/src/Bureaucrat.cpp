#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade) {
    std::cout << "constructor called for " << this->name << std::endl;
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {
    std::cout << "copy constructor called for " << this->name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "assignment operator called" << std::endl;
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "destructor called for " << this->name << std::endl;
}

const std::string Bureaucrat::getName() const {return this->name;}

int Bureaucrat::getGrade() const {return this->grade;}

void Bureaucrat::incrementGrade( void ) {
    if (grade <= HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    this->grade -= 1;
}

void Bureaucrat::decrementGrade( void ) {
    if (grade >= LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    this->grade += 1;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade is too high";
}

void Bureaucrat::signForm(Form& f) {
    try
    {
        f.beSigned(*this);
        std::cout << *this << " signed " << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << *this << " couldn't sign " << f << " because " << e.what() << std::endl;
    }
}