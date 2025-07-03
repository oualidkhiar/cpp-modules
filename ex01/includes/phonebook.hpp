#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook{
    private:
        int index;
        bool cycle_flag;
        contact **contacts;
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        static void print_table(int count, contact **contacts);
        void get_contact();
};

#endif