/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 08:40:23 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/16 08:56:25 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
public:
    Ice();
    Ice(const Ice& cp);
    Ice& operator=(const Ice& other);
    ~Ice();
    AMateria* clone() const;
    void  use(ICharacter& target);
};

Ice::Ice(): AMateria("ice"){}

Ice::Ice(const Ice& cp){
    type = cp.type;
}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const {
    return (new Ice());
}

void  Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

#endif