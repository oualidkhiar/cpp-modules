/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:04:08 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/31 06:03:54 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed() {
    this->fx_nb = 0;
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& OldObj) {
    this->fx_nb = OldObj.fx_nb;
    std::cout << "copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "member function getRawBits called" << std::endl;
    return (this->fx_nb);
}

void Fixed::setRawBits( int const raw ) {
    this->fx_nb = raw;
    std::cout << "member function setRawBits called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}
