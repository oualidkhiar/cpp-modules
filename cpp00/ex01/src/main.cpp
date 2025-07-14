#include "../includes/phonebook.hpp"


// read io manipolators : https://www.geeksforgeeks.org/cpp/manipulators-in-c-with-examples/
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
