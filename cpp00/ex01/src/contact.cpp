#include "../includes/contact.hpp"

std::string format_field(std::string str)
{
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

bool contact::set_information()
{
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

std::string contact::get_information(std::string target)
{
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