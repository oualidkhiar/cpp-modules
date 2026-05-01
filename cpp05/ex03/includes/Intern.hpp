#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

typedef AForm* (*FormCreator)(const std::string&);

class Intern {
public:

    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

};

AForm* createPresidential(const std::string& target);
AForm* createRobotomy(const std::string& target);
AForm* createShrubbery(const std::string& target);

#endif