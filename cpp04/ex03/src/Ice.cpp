/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:04:16 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 12:05:27 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

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
