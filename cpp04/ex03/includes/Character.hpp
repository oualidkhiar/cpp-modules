/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:57:37 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/14 17:52:57 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define SIZEINVENTORY 4
#include <iostream>
#include <ICharacter.hpp>

class Character: public ICharacter {
private:
    AMateria *inventory[SIZEINVENTORY];    
public:
    Character();
    ~Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};


Character::Character() {
    for (int i =0; i < SIZEINVENTORY; i++) {
        this->inventory[i] = NULL;
    }
}
Character::Character(const Character& other) {
    for (int i = 0; i < SIZEINVENTORY; i++) {
        if (other.inventory[i]) {
            this->inventory[i] = other.inventory[i]->clone();
        }
        else {this->inventory[i] = NULL;}
    }
}
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        for (int i = 0; i < SIZEINVENTORY; i++) {
            if (inventory[i]) {
                this->inventory[i] = other.inventory[i]->clone();
            }
            else {this->inventory[i] = NULL;}
        }
    }
    return *this;
}
Character::~Character() {
    for (int i = 0; i < SIZEINVENTORY; i++) {
        delete inventory[i];
    }
}
void Character::equip(AMateria* m) {
    for (int i = 0; i < SIZEINVENTORY; i++) {
        if (!(inventory[i])) {
            this->inventory[i] = m;
            return ;
        }
    }
}
void Character::unequip(int idx) {
    if (idx >= 0 && idx < SIZEINVENTORY && inventory[idx]) {
        inventory[idx] = NULL;
    }
}
void Character::use(int idx, ICharacter& target) {
    this->inventory[idx]->use(target);
}

#endif