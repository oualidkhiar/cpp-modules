/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:37:29 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/07 18:56:34 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    hit_pts = 100;
    Energy_pts = 50;
    Attack_dmg = 20;
    std::cout << "default constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    hit_pts = 100;
    Energy_pts = 50;
    Attack_dmg = 20;
    std::cout << "default constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cp) {
    std::cout << "Copy constructor for ScavTrap called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        std::cout << "copy assignment operator for ScavTrap called" << std::endl;
    }
    else 
        std::cout << "self assignment for ScavTrap detected" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "deconstructor for ScavTrap Called" << std::endl;   
}