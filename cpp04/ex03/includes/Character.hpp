/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:57:37 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/16 09:16:46 by Oukhiar          ###   ########.fr       */
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
    std::string _name;
public:
    Character(std::string name);
    ~Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    
    std::string const & getName() const;
    AMateria* getMatria(int indx) const;

    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};


Character::Character(std::string name): _name(name) {
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
AMateria* Character::getMatria(int indx) const {
    return this->inventory[indx];
}
std::string const & Character::getName() const{
    return this->_name;
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