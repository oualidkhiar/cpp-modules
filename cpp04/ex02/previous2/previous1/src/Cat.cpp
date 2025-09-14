/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:41:09 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/05 13:18:32 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(): Animal("Cat") {
    this->B = new Brain();
    std::cout << "constructor called for Cat class type " << this->type << std::endl;
}

Cat::Cat(const Cat& cp): Animal(cp){
    delete this->B;
    this->B = new Brain(*cp.B);
    std::cout << "copy constructor called for Cat class type " << this->type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->type = other.type;
        delete this->B;
        this->B = new Brain(*other.B);
    }
    std::cout << "copy assignment operator called for Cat class type " << this->type << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->B;
    std::cout << "deconstructor called for Cat class type " << this->type << std::endl;
}

void Cat::makeSound( void ) const {
    std::cout << "Cat sound" << std::endl;
}

void Cat::setIdea(std::string idea, int index) {
    this->B->setIdea(idea, index);
}

std::string Cat::getIdea(int index) {
    return this->B->getIdea(index);
}
