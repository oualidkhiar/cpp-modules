#include "../includes/AForm.hpp"

AForm::AForm(std::string name, const int Sign_grade, const int execute_Grade): 
name(name), Signed(false), grade_to_sign(Sign_grade), grade_to_execute(execute_Grade)
{
    if (Sign_grade < HIGHEST_GRADE || execute_Grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    } else if (Sign_grade > LOWEST_GRADE || execute_Grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other): 
name(other.name), Signed(other.Signed), grade_to_sign(other.grade_to_sign), 
grade_to_execute(other.grade_to_execute) {}

AForm& AForm::operator=(const AForm& other) {
    this->Signed = other.Signed;
    return *this;
}

AForm::~AForm() {
    std::cout << "deconstrictor called for name: " << this->name << " class AForm" << std::endl;
}

const std::string AForm::getName() const {return this->name;}
const int AForm::getGradeExecute() const {return this->grade_to_execute;}
const int AForm::getGradetoSign() const {return this->grade_to_sign;}
bool AForm::isSigned() {return this->Signed;}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed yet";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
    os << obj.getName() << ", form grade to execute is " <<
    obj.getGradeExecute() << ", form grade to sign is " << 
    obj.getGradetoSign();
    return os;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= this->grade_to_sign) {
        this->Signed = true;
    } else {
        throw GradeTooLowException();
    }
}

void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!this->Signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->grade_to_execute) {
        throw GradeTooLowException();
    }
}