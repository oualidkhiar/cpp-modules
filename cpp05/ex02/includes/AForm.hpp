
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150


class Form {
private:

    const std::string   name;
    bool                Signed;
    const int           grade_to_sign;
    const int           grade_to_execute;

public:

    // constructors
    Form(std::string name, const int Sign_grade, const int execute_Grade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // geters
    const std::string getName() const;
    const int getGradeExecute() const;
    const int getGradetoSign() const;
    bool isSigned();

    // other member functions
    void beSigned(const Bureaucrat& b);

    // exceptions classes
    class GradeTooHighException: public std::exception
    {
        public:
            const char *what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
            const char *what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif