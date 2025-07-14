/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:14:40 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/14 13:06:05 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define OPTIONS 4
class Harl;
typedef void (Harl::*FuncPtr) ( void );

class Harl
{
    private:

        FuncPtr FPtr[4];
        std::string Levels[4];

        void debug( void );
        void info( void );
        void warning( void );
        void error( void );

    public:

        Harl();
        void complain( std::string level );

};

#endif
