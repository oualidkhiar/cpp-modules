/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:16 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/11 18:00:24 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPPP
# define DIAMONDTRAP_HPPP

#include "./prev_ex/FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
private:
    std::string DName;
public:

    DiamondTrap(): ClapTrap() {
        std::cout << "constructor called for DiamondTrap " << this->DName << std::endl;
    }

    DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), DName(name) {
        std::cout << "constructor called for DiamondTrap " << this->DName << std::endl;
    };

    DiamondTrap(const DiamondTrap& cp) {
        this->DName = cp.DName;
        this->name = cp.name;
        this->Energy_pts = cp.Energy_pts;
        this->hit_pts = cp.hit_pts;
        this->Attack_dmg = cp.Attack_dmg;
        this->GateFlag = cp.GateFlag;
        std::cout << "copy constructor called for DiamondTrap " << this->DName << std::endl; 
    }

    DiamondTrap& operator=(const DiamondTrap& other) {
        if (this != &other) {
            this->DName = other.DName;
            this->name = other.name;
            this->Energy_pts = other.Energy_pts;
            this->hit_pts = other.hit_pts;
            this->Attack_dmg = other.Attack_dmg;
            this->GateFlag = other.GateFlag;
            std::cout << "copy assignment operator called for DiamondTrap " << this->DName << std::endl;
        }
        else
            std::cout << "self assignment operator detected for DiamondTrap " << this->DName << std::endl;
        return *this;
    }

    ~DiamondTrap() {
        std::cout << "deconstructor called for DiamondTrap " << this->DName << std::endl; 
    };

    void whoAmI() {
        std::cout << "I'm DiamondTrap " << this->DName << " ClapTrap " << this->name << std::endl;
    }

};




#endif