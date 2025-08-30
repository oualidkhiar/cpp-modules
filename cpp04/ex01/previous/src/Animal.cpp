/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:39:58 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 16:07:23 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(): type("default"){
    std::cout << "constructor called for Animal class type " << this->type << std::endl;
}

Animal::Animal(std::string type): type(type) {
    std::cout << "constructor called for Animal class type " << this->type << std::endl;
}

Animal::Animal(const Animal& cp) {
    this->type = cp.type;
    std::cout << "copy constructor called for Animal class type " << this->type << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "copy assignment operator called for Animal class type " << this->type << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "deconstructor called for Animal class type " << this->type << std::endl;
}

void Animal::makeSound( void ) const{
    std::cout << "Animal" << std::endl;
}

std::string Animal::getType() const{
    return this->type;
}
