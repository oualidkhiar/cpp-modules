#include "../includes/Form.hpp"

Form::Form(std::string name, const int Sign_grade, const int execute_Grade): 
name(name), Signed(false), grade_to_sign(Sign_grade), grade_to_execute(execute_Grade) {
    std::cout << "constructor called name: " << this->name << " class Form" << std::endl;
    if (grade_to_execute < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }else if (grade_to_execute > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    if (grade_to_sign < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }else if (grade_to_sign > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other): 
name(other.name), Signed(other.Signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
    std::cout << "copy constructor called for name: " << this->name << " class Form" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "copy assignment operator called for name: " << this->name << " class Form" << std::endl;
    this->Signed = other.Signed;
    return *this;
}

Form::~Form() {
    std::cout << "deconstrictor called for name: " << this->name << " class Form" << std::endl;
}

const std::string Form::getName() const {return this->name;}
const int Form::getGradeExecute() const {return this->grade_to_execute;}
const int Form::getGradetoSign() const {return this->grade_to_sign;}
bool Form::isSigned() {return this->Signed;}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
    os << obj.getName() << ", form grade to execute is " <<
    obj.getGradeExecute() << ", form grade to sign is " << 
    obj.getGradetoSign();
    return os;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= this->grade_to_sign) {
        this->Signed = true;
    } else {
        throw GradeTooLowException();
    }
}
