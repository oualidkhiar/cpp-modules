#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits> 

std::string format_field(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

std::string get_input_from_user(const std::string &msg)
{
    std::string input;
    size_t start;

    start = 0;
    std::cout << msg;
    std::getline(std::cin, input);
    if (std::cin.eof()) {
        std::cout << "\nEnd of input detected (EOF).\n";
        exit(0);
    }
    while (start < input.length() && std::isspace(input[start]))
        start++;
    return (input.substr(start, input.length() - start));
}

class contact{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;
    public:
        bool set_information(){
            firstname = get_input_from_user("Enter the first name: ");
            if (firstname.length() == 0)
                return false;
            lastname = get_input_from_user("Enter the last name: ");
            if (lastname.length() == 0)
                return false;
            nickname = get_input_from_user("Enter the nick name: ");
            if (nickname.length() == 0)
                return false;
            phonenumber = get_input_from_user("Enter the phone number: ");
            if (phonenumber.length() == 0)
                return false;
            darkestsecret = get_input_from_user("Enter the darkest secret: ");
            if (darkestsecret.length() == 0)
                return false;
            return true;
        }
        std::string get_information(std::string target){
            if (target == "FIRSTNAME")
                return (firstname);
            else if (target == "LASTNAME")
                return (lastname);
            else if (target == "PHONENUMBER")
                return (phonenumber);
            else if (target == "NICKNAME")
                return (nickname);
            else if (target == "DARKESTSECRET")
                return(darkestsecret);
            return (NULL);
        }
};

class PhoneBook{
    private:
        int index;
        bool cycle_flag;
        contact **contacts;
    public:
        PhoneBook(){
            contacts = new contact*[8];
            for (int i = 0; i < 8; i++){
                contacts[i] = new contact;
            }
            index = 0;
            cycle_flag = false;
        }
        ~PhoneBook(){
            for (int i = 0; i < 8; i++){
                delete contacts[i];
            }
            delete[] contacts;
        }
        void add_contact(){
            contact *tmp;
            if (index == 8)
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
        static void print_table(int count, contact **contacts) {
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
        void get_contact() {
            std::string num_str;
            int i;

            if (!cycle_flag) {
                if (index >= 1)
                    print_table(index, contacts);
            }
            else {
                print_table(8, contacts);
            }
            num_str = get_input_from_user("Enter the index you want: ");
            if (std::cin.fail())
                return ;
            if (num_str.length() == 1 && std::isdigit(num_str[0]))
                i = num_str[0] - '0';
            else {
                std::cout << "Invalid index!\ntry using integer value from 1 to 8\n";
                return;
            }
            if (i < 1) {
                std::cout << "Invalid index!\ntry using integer value from 1 to 8\n";
                return ;
            }
            if (i > index && !cycle_flag) {
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
};

int main()
{
    PhoneBook *Book = new PhoneBook;
    bool p_flag = true;
    std::string option;

    while (true)
    {
        if (p_flag)
        {
            std::cout << "  You have three options:\n";
            std::cout << "   *  ADD: Add a contact to your PhoneBook\n";
            std::cout << "   *  SEARCH: Search for a contact by index\n";
            std::cout << "   *  EXIT: Exit the program\n";
            p_flag = false;
        }
        option = get_input_from_user("Enter your option: ");
        if (option == "ADD")
            Book->add_contact();
        else if (option == "SEARCH")
            Book->get_contact();
        else if (option == "EXIT")
            break ;
    }
    delete Book;
    return (0);
}
