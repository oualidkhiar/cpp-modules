/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:09:37 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/11 15:33:01 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string init_type): type(init_type) {}

const std::string& Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string new_type)
{
    type = new_type;
}
