#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
private:

    const std::string   name;
    int                 grade;
    Bureaucrat& operator=(const Bureaucrat& other);

public:

    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string getName() const ;
    int getGrade() const;

    void incrementGrade( void );
    void decrementGrade( void );

    void GradeTooHighException();
    void  GradeTooLowException();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
