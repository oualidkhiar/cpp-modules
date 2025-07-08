
#include "../includes/phonebook.hpp"
#include <utility>

PhoneBook::PhoneBook(){
    contacts = new contact*[CONTACTS_SIZE];
    for (int i = 0; i < CONTACTS_SIZE; i++){
        contacts[i] = new contact;
    }
    index = 0;
    cycle_flag = false;
}

PhoneBook::~PhoneBook(){
    for (int i = 0; i < CONTACTS_SIZE; i++){
        delete contacts[i];
    }
    delete[] contacts;
}

void PhoneBook::add_contact()
{
    contact *tmp;

    if (index == CONTACTS_SIZE)
    {
        index = 0;
        if (!cycle_flag)
            cycle_flag = true;
    }
    if (cycle_flag){
        tmp = contacts[index];
        contacts[index] = new contact;
        delete tmp;
    }
    if (!(contacts[index]->set_information()))
        return ;
    index++;
}

void print_table(int count, contact **contacts)
{
    std::cout << "|-------------------------------------------|\n";
    std::cout << "|" << format_field("index") << "|" << format_field("firstname")
    << "|" << format_field("lastname") << "|" << format_field("nickname") << "|\n";
    std::cout << "|-------------------------------------------|\n";
    for (int i = 0; i < count; i++) {
        std::cout << "|" << format_field(std::to_string(i + 1)) << "|"
        << format_field(contacts[i]->get_information("FIRSTNAME")) << "|"
        << format_field(contacts[i]->get_information("LASTNAME")) << "|"
        << format_field(contacts[i]->get_information("NICKNAME")) << "|\n";
    }
    std::cout << "|-------------------------------------------|\n";
}

void PhoneBook::get_contact(){
        std::string num_str;
        int i;
        std::string error_msg;

        error_msg = "Invalid index!\ntry using integer value from 1 to " + std::to_string(CONTACTS_SIZE);

        if (!cycle_flag) {
            if (index >= 1)
                print_table(index, contacts);
        }
        else {
            print_table(CONTACTS_SIZE, contacts);
        }
        num_str = get_input_from_user("Enter the index you want: ");
        if (std::cin.fail())
            return ;

        bool is_nbr = num_str.length() == 1 && std::isdigit(num_str[0]);
        if (is_nbr)
            i = num_str[0] - '0';

        if (!is_nbr || i == 0) {
            std::cout << error_msg << "\n";
            return ;
        }

        if ((i > index && !cycle_flag) || i > CONTACTS_SIZE) {
            std::cout << "you have " << index << " number of contacts\n";
            return ;
        }
        std::cout << "The information of contact index " << i << " is :\n\n";
        std::cout << " * First Name: " << contacts[i - 1]->get_information("FIRSTNAME") << "\n";
        std::cout << " * Last Name: " << contacts[i - 1]->get_information("LASTNAME") << "\n";
        std::cout << " * Nick Name: " << contacts[i - 1]->get_information("NICKNAME") << "\n";
        std::cout << " * Phone Number: " << contacts[i - 1]->get_information("PHONENUMBER") << "\n";
        std::cout << " * Darkest Secret: " << contacts[i - 1]->get_information("DARKESTSECRET") << "\n\n";
}

