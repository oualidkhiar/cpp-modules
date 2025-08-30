/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:40:58 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 17:54:26 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal("Dog") {
    this->B = new Brain();
    std::cout << "constructor called for Dog class type " << this->type << std::endl;
}

Dog::Dog(const Dog& cp): Animal(cp) {
    delete this->B;
    this->B = new Brain(*(cp.B));
    std::cout << "copy constructor called for Dog class type " << this->type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->type = other.type;
        delete this->B;
        this->B = new Brain(*(other.B));
    }
    std::cout << "copy assignment operator called for Dog class type " << this->type << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->B;
    std::cout << "deconstructor called for Dog class type " << this->type << std::endl;
}

void Dog::makeSound( void ) const {
    std::cout << "Dog sound" << std::endl;
}

void Dog::setIdea(std::string idea, int index) {
        this->B->setIdea(idea, index);
}

std::string Dog::getIdea(int index) {
    return this->B->getIdea(index);
}