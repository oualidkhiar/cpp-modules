/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:03:30 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 13:55:29 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(): AMateria("cure"){}

Cure::Cure(const Cure& cp){
    type = cp.type;
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const {
    return (new Cure());
}

void  Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}