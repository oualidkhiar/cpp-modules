/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:54:05 by oukhiar           #+#    #+#             */
/*   Updated: 2025/08/06 16:10:58 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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