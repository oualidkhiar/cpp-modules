/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:01:13 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 13:33:25 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

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

void AMateria::use(ICharacter& target) {
    std::cout << "default " << target.getName() << std::endl;
}