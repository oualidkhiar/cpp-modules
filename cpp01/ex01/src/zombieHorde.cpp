/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:41:55 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/14 16:07:04 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
		return (NULL);
	Zombie *zombies;
	zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zombies[i].set_the_name(name);
	}
	return (zombies);
}
