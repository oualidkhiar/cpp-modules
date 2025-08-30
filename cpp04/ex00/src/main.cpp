/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:39:31 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 16:36:21 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"


int main()
{

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "Wrong test bigining " << std::endl;


    delete meta;
    delete j;
    delete i;

    const WrongAnimal *w = new WrongAnimal();
    const WrongAnimal *cw = new WrongCat();
    
    std::cout << cw->getType() << " " << std::endl;
    w->makeSound();
    cw->makeSound();
    delete w;
    delete cw;

    return 0;

}






