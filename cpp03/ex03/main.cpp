/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:13:43 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/12 14:04:20 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {

    DiamondTrap obj("SCAVGHD");
    DiamondTrap A = obj;

    std::cout << std::endl;
    std::cout << std::endl;

    obj.attack("ana");
    obj.takeDamage(100);
    obj.beRepaired(45);
    obj.GetStatus();
    obj.whoAmI();

    std::cout << "for A " << std::endl;
    std::cout << std::endl;
    std::cout << "STATUS a" << std::endl;
    A.GetStatus();

}

