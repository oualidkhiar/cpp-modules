#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
class Form;

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
private:

    const std::string   name;
    int                 grade;
    
    public:
    
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    
    const std::string getName() const ;
    int getGrade() const;

    void incrementGrade( void );
    void decrementGrade( void );

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
    // added function
    void signForm(Form& f);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
