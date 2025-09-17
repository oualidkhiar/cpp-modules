/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:01:56 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 14:03:51 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

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
    if (indx >= 0 && indx < SIZEINVENTORY && inventory[indx]) {
        return this->inventory[indx];
    }
    else {
        return NULL;
    }
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
    if (idx < SIZEINVENTORY && idx >= 0 && this->inventory[idx]) {
        this->inventory[idx]->use(target);
    }
}