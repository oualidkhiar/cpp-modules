/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:55:55 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/14 15:55:35 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
int main()
{	
	{
		Zombie *first = newZombie("walid khair");
		first->announce();
		delete first;
	}
	{
		randomChump("khiar");
	}
}
