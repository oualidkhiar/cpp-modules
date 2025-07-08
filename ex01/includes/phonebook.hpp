#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

#ifndef CONTACTS_SIZE
#define CONTACTS_SIZE 8
#endif

class PhoneBook{
    private:
        int index;
        bool cycle_flag;
        contact **contacts;
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        void get_contact();
};

void print_table(int count, contact **contacts);

#endif