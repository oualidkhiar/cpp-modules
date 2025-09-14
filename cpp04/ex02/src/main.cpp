/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:04:08 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/06 13:47:06 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../previous2/previous1/includes/Dog.hpp"
#include "../previous2/previous1/includes/Cat.hpp"
#include "../previous2/previous1/includes/WrongCat.hpp"


int main()
{

    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    // meta->makeSound();

    ((Dog *)j)->setIdea("walid", 1);
    std::cout << ((Dog *)j)->getIdea(10) << std::endl;

    // delete meta;
    delete i;
    delete j;

    return 0;

}
