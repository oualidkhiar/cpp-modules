/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:37:29 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/08 14:33:05 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    this->hit_pts = 100;
    this->Energy_pts = 50;
    this->Attack_dmg = 20;
    this->GateFlag = false;
    std::cout << "default constructor for ScavTrap " << this->name << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    this->hit_pts = 100;
    this->Energy_pts = 50;
    this->Attack_dmg = 20;
    this->GateFlag = false;
    std::cout << "default constructor for ScavTrap " << this->name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cp): ClapTrap(cp){
    this->GateFlag = false;
    std::cout << "Copy constructor for ScavTrap " << this->name << " called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->Attack_dmg = other.Attack_dmg;
        this->Energy_pts = other.Energy_pts;
        this->hit_pts = other.hit_pts;
        this->GateFlag = other.GateFlag;
        std::cout << "copy assignment operator for ScavTrap " << this->name << " called" << std::endl;
    }
    else 
        std::cout << "self assignment for ScavTrap " << this->name << " detected" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "deconstructor for ScavTrap " << this->name << " called" << std::endl;   
}

void ScavTrap::attack( std::string target ) {
    if (this->Energy_pts == 0)
        std::cout << "ScavTrap " << this->name << " can't do this action because hit has 0 Energy points" << std::endl;
    else if (this->hit_pts == 0)
        std::cout << "ScavTrap " << this->name << " is already dead and can't attack" << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->name << " Attack " << target << " causing " << this->Attack_dmg  << " points of damage" << std::endl;
        this->Energy_pts--;
    }
}

void ScavTrap::guardGate() {
    if (this->Energy_pts == 0)
        std::cout << "ScavTrap " << this->name << " can't do this action because hit has 0 Energy points" << std::endl;
    else if (this->hit_pts == 0)
        std::cout << "ScavTrap " << this->name << " is already dead and can't attack" << std::endl;
    else
    {
        if (!(this->GateFlag)) {
            this->GateFlag = true;
            std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
            this->Energy_pts--;
        }
        else
            std::cout << "ScavTrap " << this->name << " is already in Gate keeper mode" << std::endl;
    }
}


void ScavTrap::GetStatus(void) {
    std::cout << "Status is >> "<< this->name << ": HitPts " << this->hit_pts << ": EnergyPts " << this->Energy_pts << ": AttackDmg " << this->Attack_dmg << std::endl;
}

