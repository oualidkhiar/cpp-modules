/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:17:21 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/14 16:11:45 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon &cb): name(nm), club(cb) {}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->club.getType() 
    << std::endl;
}
