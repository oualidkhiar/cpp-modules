/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:37:02 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/12 11:47:34 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <ICharacter.hpp>

class AMateria {
protected:
    std::string type;
public:
    AMateria();
    ~AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria& cp);
    AMateria& operator=(const AMateria& other);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

AMateria::AMateria(std::string const & type): type(type) {}

AMateria::AMateria(): type("defaultTp") {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& cp): type(cp.type){}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    return this->type;
}

AMateria* AMateria::clone() const{}

void AMateria::use(ICharacter& target) {
    
}

#endif