/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:04:42 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 15:06:02 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << "constructor called for WrongCat class type " << this->type << std::endl;
}

WrongCat::WrongCat(const WrongCat& cp): WrongAnimal(cp) {
    std::cout << "copy constructor called for WrongCat class type " << this->type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "copy assignment operator called for WrongCat class type " << this->type << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "deconstructor called for WrongCat class type " << this->type << std::endl;
}

void WrongCat::makeSound( void ) const {
    std::cout << "WrongCat sound" << std::endl;
}
