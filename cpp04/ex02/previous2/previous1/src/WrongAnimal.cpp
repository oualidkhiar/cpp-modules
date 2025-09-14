/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:03:42 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 17:39:34 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("default"){
    std::cout << "constructor called for WrongAnimal class type " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type) {
    std::cout << "constructor called for WrongAnimal class type " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cp) {
    this->type = cp.type;
    std::cout << "copy constructor called for WrongAnimal class type " << this->type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "copy assignment operator called for WrongAnimal class type " << this->type << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "deconstructor called for WrongAnimal class type " << this->type << std::endl;
}

void WrongAnimal::makeSound( void ) const{
    std::cout << "WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const{
    return this->type;
}