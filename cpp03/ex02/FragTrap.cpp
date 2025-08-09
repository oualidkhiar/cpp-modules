/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:47:27 by oukhiar           #+#    #+#             */
/*   Updated: 2025/08/08 15:06:54 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
    this->hit_pts = 100;
    this->Energy_pts = 100;
    this->Attack_dmg = 30;
    std::cout << "default constructor for FragTrap " << this->name << " called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->hit_pts = 100;
    this->Energy_pts = 100;
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

