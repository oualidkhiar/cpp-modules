#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits> 

// first introduction ex00 
// struct st{
//     char *str;
//     void print_lower(){
//         for (int i = 0; str[i]; i++){
//             if (str[i] >= 97 && str[i] <= 122){
//                 str[i] -= 32;
//                 std::cout << str[i];
//             }
//             else
//                 std::cout << str[i];
//         }
//     }
// };

// int main(int ac, char **av){
//     st arg_cap;
//     for (int i = 1; av[i]; i++){
//         arg_cap.str = av[i];
//         arg_cap.print_lower();
//     }
//     return (0);
// }
//  finish ex00

// ex01

std::string format_field(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
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
            std::cout << "Enter the first name: ";
            std::getline(std::cin, firstname);
            if (std::cin.fail() || firstname.length() == 0)
                return false;
            if (std::cin.eof()) {
                std::cout << "End of input detected (EOF).\n";
                return false;
            }
            std::cout << "Enter the last name: ";
            std::getline(std::cin, lastname);
            if (std::cin.fail() || lastname.length() == 0)
                return false;
            if (std::cin.eof()) {
                std::cout << "End of input detected (EOF).\n";
                return false;
            }
            std::cout << "Enter the nickname: ";
            std::getline(std::cin, nickname);
            if (std::cin.fail() || nickname.length() == 0)
                return false;
            if (std::cin.eof()) {
                std::cout << "End of input detected (EOF).\n";
                return false;
            }
            std::cout << "Enter the phone number: ";
            std::getline(std::cin, phonenumber);
            if (std::cin.fail() || phonenumber.length() == 0)
                return false;
            if (std::cin.eof()) {
                std::cout << "End of input detected (EOF).\n";
                return false;
            }
            std::cout << "Enter the darkestsecret: ";
            std::getline(std::cin, darkestsecret);
            if (std::cin.fail() || darkestsecret.length() == 0)
                return false;
            if (std::cin.eof()) {
                std::cout << "End of input detected (EOF).\n";
                return false;
            }
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
            if (!(contacts[index]->set_information())){
                std::cout << "\nEnd of input detected (EOF).\n";
                exit(0);
            }
            index++;
        }
        void print_table(int count, contact **contacts) {
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
            std::cout << "Enter the index you want: ";
            std::getline(std::cin, num_str);
            if (std::cin.eof()) {
                std::cout << "\nEnd of input detected (EOF).\n";
                exit(0);
            }
            if (std::cin.fail())
                return ;
            if (num_str.length() == 1 && std::isdigit(num_str[0]))
                i = num_str[0] - '0';
            else {
                std::cout << "Invalid index!\ntry using integer value between 1 and 8\n";
                return;
            }
            if (i < 1) {
                std::cout << "Invalid index!\ntry using integer value between 1 and 8\n";
                return ;
            }
            if (i > index && !cycle_flag) {
                std::cout << "you have just " << index << " number of contacts\n";
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
        std::cout << "Enter your option: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.eof()) {
            std::cout << "\nEnd of input detected (EOF).\n";
            exit(0);
        }
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
