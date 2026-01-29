
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Form {
private:

    const std::string   name;
    bool                Signed;
    const int           grade;

public:

    Form();
    ~Form();
};

Form::Form()
{
}

Form::~Form()
{
}



#endif