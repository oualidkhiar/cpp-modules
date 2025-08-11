/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:54:05 by oukhiar           #+#    #+#             */
/*   Updated: 2025/08/10 15:45:24 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap a;

    for (int i = 0; i < 3; i++) {
        a.GetStatus();
        a.attack("someOthehr");
        a.takeDamage(95);
        a.beRepaired(85);
        a.highFivesGuys();
        a.GetStatus();
    }
}