/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:04:03 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/31 05:54:37 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int fx_nb;
        static const int  FractionalBits;
    public:
        Fixed();
        Fixed(const Fixed& OldObj);
        ~Fixed();
        Fixed& operator=(const Fixed& other);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif
