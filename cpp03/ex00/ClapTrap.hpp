/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:54:00 by oukhiar           #+#    #+#             */
/*   Updated: 2025/08/06 16:07:00 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:

    std::string name;
    unsigned int hit_pts;
    unsigned int Energy_pts;
    unsigned int Attack_dmg;

public:

    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& Other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif