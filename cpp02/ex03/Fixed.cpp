/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:04:08 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/04 10:15:21 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed() {
    this->fx_nb = 0;
}

Fixed::Fixed(const int val){
    this->fx_nb = val << FractionalBits;
}

Fixed::Fixed(const float val) {
    this->fx_nb = roundf(val * (1 << FractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    this->fx_nb = other.fx_nb;
}

Fixed::~Fixed() {}

int Fixed::getRawBits( void ) const {
    return (this->fx_nb);
}

void Fixed::setRawBits( int const raw ) {
    this->fx_nb = raw;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
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

bool Fixed::operator>(const Fixed& other) const {
    return this->fx_nb > other.fx_nb;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->fx_nb > other.fx_nb;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->fx_nb >= other.fx_nb;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->fx_nb <= other.fx_nb;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->fx_nb == other.fx_nb;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->fx_nb != other.fx_nb;
}

Fixed& Fixed::operator++() {
    ++fx_nb;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed cp = *this;
    fx_nb++;
    return cp;
}

Fixed& Fixed::operator--() {
    --fx_nb;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed cp = *this;
    fx_nb--;
    return cp;
}

Fixed Fixed::operator*(const Fixed& Other) const {
    Fixed res;
    res.fx_nb = (this->fx_nb * Other.fx_nb) >> FractionalBits;
    return res;
}

Fixed Fixed::operator/(const Fixed& Other) const{
    Fixed res;
    res.fx_nb = (this->fx_nb << FractionalBits) / Other.fx_nb;
    return res;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    else
        return b; 
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    else
        return b; 
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
        return a;
    else
        return b; 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    else
        return b; 
}
