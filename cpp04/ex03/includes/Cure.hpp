/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 08:56:55 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/16 08:59:00 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
public:
    Cure();
    Cure(const Cure& cp);
    Cure& operator=(const Cure& other);
    ~Cure();
    AMateria* clone() const;
    void  use(ICharacter& target);
};

Cure::Cure(): AMateria("Cure"){}

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

#endif