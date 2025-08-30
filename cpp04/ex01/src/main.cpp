/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:39:31 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 19:06:51 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../previous/includes/Dog.hpp"
#include "../previous/includes/Cat.hpp"
#include "../previous/includes/WrongCat.hpp"


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

    Cat *ptrc = const_cast<Cat*>(static_cast<const Cat *>(i));
    const Cat& refc = static_cast<const Cat&>(*i);
    Cat *ptr = (Cat *)i;
 
    std::cout << "start" << std::endl;
    ptrc->makeSound();
    ptr->setIdea("sidi walid", 1);

    std::cout << ptrc << ",   " << (Cat *)i << " , " << &refc << std::endl;
    std::cout << std::endl;

    Dog *d = new Dog();

    d->makeSound();
    d->setIdea("cat mewmew pour manger", 0);
    std::cout << d->getIdea(1000) << std::endl;

    Dog *d2 = new Dog(*d);

    *d2 = *d;

    std::cout << d2->getIdea(0) << std::endl;
    delete d;
    delete d2;
    delete meta;
    delete i;
    delete j;

    return 0;

}

