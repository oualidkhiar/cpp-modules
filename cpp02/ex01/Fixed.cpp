/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:04:08 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/01 14:30:04 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed() {
    this->fx_nb = 0;
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int val){
    this->fx_nb = val << FractionalBits;
    std::cout << "INT default constructor called" << std::endl;
}

Fixed::Fixed(const float val) {
    this->fx_nb = roundf(val * (1 << FractionalBits));
    std::cout << "FLOAT default constructor called" << std::endl;
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
        this->fx_nb = other.fx_nb;
    }
    return *this;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(this->fx_nb) / (1 << FractionalBits);
}

int Fixed::toInt( void ) const {
    return this->fx_nb / (1 << FractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& D) {
    os << D.toFloat();
    return os;
}
