/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:47:27 by oukhiar           #+#    #+#             */
/*   Updated: 2025/08/11 17:31:43 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
    this->hit_pts = 100;
    this->Attack_dmg = 30;
    std::cout << "default constructor for FragTrap " << this->name << " called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->hit_pts = 100;
    this->Attack_dmg = 30;
    std::cout << "default constructor for FragTrap " << this->name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& cp): ClapTrap(cp) {
    std::cout << "copy constructor for FragTrap " << this->name << " called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hit_pts = other.hit_pts;
        this->Energy_pts = other.Energy_pts;
        this->Attack_dmg = other.Attack_dmg;
        std::cout << "copy assignment operator for FragTrap " << this->name << " called" << std::endl;
    }
    else
        std::cout << "self assignment operator for FragTrap " << this->name << " detected" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "deconstructor for FragTrap " << this->name << " called" << std::endl;
}

void FragTrap::attack( std::string target ) {
    if (this->Energy_pts == 0)
        std::cout << "FragTrap " << this->name << " can't do this action because hit has 0 Energy points" << std::endl;
    else if (this->hit_pts == 0)
        std::cout << "FragTrap " << this->name << " is already dead and can't attack" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->name << " Attack " << target << " causing " << this->Attack_dmg  << " points of damage" << std::endl;
        this->Energy_pts--;
    }
}


void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " did high fives" << std::endl;
}

void FragTrap::GetStatus(void) {
    std::cout << "Status is >> "<< this->name << ": HitPts " << this->hit_pts << ": EnergyPts " 
    << this->Energy_pts << ": AttackDmg " << this->Attack_dmg << std::endl;
}
