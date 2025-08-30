/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:40:58 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 15:04:00 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal("Dog"){
    std::cout << "constructor called for Dog class type " << this->type << std::endl;
}

Dog::Dog(const Dog& cp): Animal(cp) {
    std::cout << "copy constructor called for Dog class type " << this->type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "copy assignment operator called for Dog class type " << this->type << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "deconstructor called for Dog class type " << this->type << std::endl;
}


void Dog::makeSound( void ) const {
    std::cout << "Dog sound" << std::endl;
}
