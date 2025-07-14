/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:20:56 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/14 16:17:08 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string nm): name(nm), club(NULL) {}

void HumanB::setWeapon(Weapon& to_set)
{
    this->club = &to_set;
}

void HumanB::attack()
{
    if (!(this->club)) {
        std::cout << this->name << " not have a weapon" << std::endl;
        return ;
    }
    std::cout << this->name << " attacks with their " << this->club->getType() 
    << std::endl;
}
