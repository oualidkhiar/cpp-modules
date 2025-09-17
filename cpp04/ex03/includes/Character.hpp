/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:57:37 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 12:17:54 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define SIZEINVENTORY 4
#include <iostream>
#include "ICharacter.hpp"

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

#endif