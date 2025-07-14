
#include <iostream>

void print_upper(char* str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            std::cout << (char)std::toupper(str[i]);
        else
            std::cout << str[i];
    }
}

int main(int ac, char **av)
{
    (void)ac;

    for (int i = 1; av[i]; i++) {
        print_upper(av[i]);
    }
    return (0);
}
