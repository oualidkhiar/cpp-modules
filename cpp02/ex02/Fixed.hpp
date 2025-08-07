/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:04:03 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/04 10:34:10 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:

        int fx_nb;
        static const int  FractionalBits;

    public:

        Fixed();
        Fixed(const int val);
        Fixed(const float val);
        Fixed(const Fixed& OldObj);
        ~Fixed();
        Fixed& operator=(const Fixed& other);

        friend std::ostream& operator<<(std::ostream& os, const Fixed& D);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        Fixed operator*(const Fixed& Other) const;
        Fixed operator/(const Fixed& Other) const;
        static Fixed& min(Fixed& a, Fixed& b);
        const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        const Fixed& max(const Fixed& a, const Fixed& b);

};

#endif
