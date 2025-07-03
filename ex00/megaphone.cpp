
#include <iostream>

struct st{
    char *str;
    void print_lower(){
        for (int i = 0; str[i]; i++){
            if (str[i] >= 97 && str[i] <= 122){
                str[i] -= 32;
                std::cout << str[i];
            }
            else
                std::cout << str[i];
        }
    }
};

int main(int ac, char **av){
    st arg_cap;
    for (int i = 1; av[i]; i++){
        arg_cap.str = av[i];
        arg_cap.print_lower();
    }
    return (0);
}