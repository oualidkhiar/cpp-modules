/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:40:08 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/05 15:13:31 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal( std::string type );
    Animal(const Animal& cp);
    Animal& operator=(const Animal& other);

    virtual ~Animal();
    virtual void makeSound( void ) const = 0;
    std::string getType() const;
};

#endif
