/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:55:55 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/09 19:42:53 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main()
{
	Zombie *first = zombieHorde(100 ,"hmed");
	if (first == NULL) {
		std::cout << "number of zombies is less then 1.\n";
		return (1);
	}
	for (int i = 0; i < 100; i++) {
		first[i].announce();
	}
	delete[] first;
}
