

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits> 

class contact{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;
    public:
        bool set_information();
        std::string get_information(std::string target);
};

std::string get_input_from_user(const std::string &msg);
std::string format_field(std::string str);
#endif
