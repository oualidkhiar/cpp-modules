/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:41:09 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 15:03:54 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(): Animal("Cat") {
    std::cout << "constructor called for Cat class type " << this->type << std::endl;
}

Cat::Cat(const Cat& cp): Animal(cp) {
    std::cout << "copy constructor called for Cat class type " << this->type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "copy assignment operator called for Cat class type " << this->type << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "deconstructor called for Cat class type " << this->type << std::endl;
}

void Cat::makeSound( void ) const {
    std::cout << "Cat sound" << std::endl;
}
