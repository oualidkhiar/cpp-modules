/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:13 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/12 14:02:24 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(), DName("default") {
    this->Energy_pts = SCAVENERG;
    std::cout << "default constructor called for DiamondTrap " << this->DName << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), DName(name) {
    this->Energy_pts = SCAVENERG;
    std::cout << "default constructor called for DiamondTrap " << this->DName << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& cp): ClapTrap(cp){
    *this = cp;
    std::cout << "copy constructor called for DiamondTrap " << this->DName << std::endl; 
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        this->DName = other.DName;
        this->name = other.name;
        this->Energy_pts = other.Energy_pts;
        this->hit_pts = other.hit_pts;
        this->Attack_dmg = other.Attack_dmg;
        this->GateFlag = other.GateFlag;
        std::cout << "copy assignment operator called f or DiamondTrap " << this->DName << std::endl;
    }
    else
        std::cout << "self assignment operator detected for DiamondTrap " << this->DName << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "deconstructor called for DiamondTrap " << this->DName << std::endl; 
};

void DiamondTrap::whoAmI() {
    std::cout << "I'm DiamondTrap " << this->DName << " ClapTrap " << this->name << std::endl;
}

void DiamondTrap::attack(std::string target) {
    ScavTrap::attack(target);
}

void DiamondTrap::GetStatus( void ) {
    std::cout << this->name << " " << this->DName << " " << this->Attack_dmg << " " << this->Energy_pts << " " << this->hit_pts << " " << std::endl;
}