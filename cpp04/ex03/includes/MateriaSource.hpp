/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:19:27 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/16 09:58:26 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#define MAX_MATERIASRC 4
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
private:
    AMateria *table[MAX_MATERIASRC];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& cp);
    const MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();
    void learnMateria(AMateria*);
};

MateriaSource::MateriaSource(): IMateriaSource() {
    for (int i = 0; i < MAX_MATERIASRC; i++) {
        table[i] = NULL;
    }
}
MateriaSource::MateriaSource(const MateriaSource& cp): IMateriaSource() {
    for (int i = 0; i < MAX_MATERIASRC; i++) {
        if (cp.table[i]) {
            this->table[i] = cp.table[i]->clone();
        }
        else {
            this->table[i] = NULL;
        }
    }
}
const MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < MAX_MATERIASRC; i++) {
            if (other.table[i]) {
                if ((this->table[i])) {
                    delete this->table[i];
                }
                this->table[i] = other.table[i]->clone();
            }
            else {
                this->table[i] = NULL;
            }
        }
    }
    return *this;
}
MateriaSource::~MateriaSource() {
    for (int i = 0; i < MAX_MATERIASRC; i++) {
        if (table[i]) {
            delete table[i];
        }
    }
}
void MateriaSource::learnMateria(AMateria* m) {
    
}

#endif
