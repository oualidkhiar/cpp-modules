/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:16:16 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/11 15:44:18 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main () {
    std::string str =  "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "memory address of string variable:    " << &str << "\n";
    std::cout << "The memory address held by stringPTR: " << stringPTR << "\n";
    std::cout << "The memory address held by stringREF: " << &stringREF << "\n\n";

    std::cout << "memory address of string variable:    " << str << "\n";
    std::cout << "The memory address held by stringPTR: " << *stringPTR << "\n";
    std::cout << "The memory address held by stringREF: " << stringREF << "\n";
}
