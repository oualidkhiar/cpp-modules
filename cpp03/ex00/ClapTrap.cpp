/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:53:52 by oukhiar           #+#    #+#             */
/*   Updated: 2025/08/08 14:12:48 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Oualid"), hit_pts(10), Energy_pts(10), Attack_dmg(0) {
        std::cout << "default constructor for ClapTrap " << name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hit_pts(10), Energy_pts(10), Attack_dmg(0) {
        std::cout << "default constructor for ClapTrap " << name << " called" << std::endl;
}

ClapTrap::~ClapTrap() {
        std::cout << "destructor called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& Other): name(Other.name), hit_pts(Other.hit_pts), Energy_pts(Other.Energy_pts), Attack_dmg(Other.Attack_dmg) {
    std::cout << "Copy constructor called for ClapTrap: " << this->name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hit_pts = other.hit_pts;
        this->Energy_pts = other.Energy_pts;
        this->Attack_dmg = other.Attack_dmg;
        std::cout << "Copy assignment operator called for ClapTrap: " << this->name << std::endl;
    }
    else
        std::cout << "Self assignment detected for ClapTrap: " << this->name << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->Energy_pts == 0)
        std::cout << "ClapTrap " << this->name << " can't do this action because hit has 0 Energy points" << std::endl;
    else if (this->hit_pts == 0)
        std::cout << "ClapTrap " << this->name << " is already dead and can't attack" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " Attack " << target << " causing " << this->Attack_dmg  << " points of damage" << std::endl;
        this->Energy_pts--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->Energy_pts == 0)
        std::cout << "ClapTrap " << this->name << " can't do this action because it has 0 Energy points" << std::endl;
    else if (this->hit_pts == 0)
        std::cout << "ClapTrap " << this->name << " is already dead and can't takes damage" << std::endl;
    else
    {
        if (amount > this->hit_pts)
            this->hit_pts = 0;
        else
            this->hit_pts -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->Energy_pts == 0)
        std::cout << "ClapTrap " << this->name << " can't do this action because it has 0 energy points." << std::endl;
    else if (this->hit_pts == 0)
        std::cout << "ClapTrap " << this->name << " is already dead and can't be repaired." << std::endl;
    else {
        this->hit_pts += amount;
        std::cout << "ClapTrap " << this->name << " repaired itself for " << amount << " hit points." << std::endl;
        this->Energy_pts--;
    }
}

