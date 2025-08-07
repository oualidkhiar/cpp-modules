/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:54:05 by oukhiar           #+#    #+#             */
/*   Updated: 2025/08/07 13:14:07 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap a;
    ClapTrap b("other");

    for (int i = 0; i < 10; i++)
    {
        a.attack("name");
        a.beRepaired(2);
        a.takeDamage(5);
    }
}