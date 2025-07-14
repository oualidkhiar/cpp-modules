/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:16:32 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/14 16:25:12 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl()
{
    FPtr[0] = &Harl::debug;
    FPtr[1] = &Harl::info;
    FPtr[2] = &Harl::warning;
    FPtr[3] = &Harl::error;
    Levels[0] = "DEBUG";
    Levels[1] = "INFO";
    Levels[2] = "WARNING";
    Levels[3] = "ERROR";
}

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger.\n\
I really do!" 
    << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra \
bacon costs more money.\nYou didn’t put \
enough bacon in my burger! If you did, I \
wouldn’t be asking for more!" 
    << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some \
extra bacon for free.\nI’ve been coming for \
years whereas you started working \
here since last month." 
    << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout <<  "This is unacceptable! I \
want to speak to the manager now." 
    << std::endl;
}

void Harl::complain( std::string level )
{
    for (int i = 0; i < OPTIONS; i++) {
        if (this->Levels[i] == level)
        {
            (this->*FPtr[i])();
            return ;
        }
    }
    std::cout << "This level not found!." << std::endl;
} 