/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:39:31 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 14:38:41 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../previous/includes/Dog.hpp"
#include "../previous/includes/Cat.hpp"
#include "../previous/includes/WrongCat.hpp"

#define ARRAYSIZE 10

int main()
{

    const Animal* meta = new Animal();
    const Animal* obj[ARRAYSIZE];
    std::string DodIdeas[5];
    DodIdeas[0] = "Where’s my ball?";
    DodIdeas[1] = "Food! Food! Food!";
    DodIdeas[2] = "I hear the doorbell… must bark!";
    DodIdeas[3] = "Nap time in the sun.";
    DodIdeas[4] = "Human is home, tail wagging mode ON!";
    std::string CatIdeas[5];
    CatIdeas[0] = "This box is mine now.";
    CatIdeas[1] = "I’ll knock that glass off the table…";
    CatIdeas[2] = "Nap number 7 of the day.";
    CatIdeas[3] = "You may pet me… oh wait, not anymore.";
    CatIdeas[4] = "I am the ruler of this house.";
    int j = 0;
    int k = 0;
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (i%2) {
            obj[i] = new Dog();
            ((Dog *)(obj[i]))->setIdea(DodIdeas[j++], i);
        }
        else {
            obj[i] = new Cat();
            ((Cat *)(obj[i]))->setIdea(CatIdeas[k++], i);
            
        }
    }
    std::cout << meta->getType() << std::endl;
    meta->makeSound();
    for (int i = 0; i < ARRAYSIZE; i++) {
        std::cout << obj[i]->getType() << std::endl;
        obj[i]->makeSound();
        if (i%2)
            std::cout << ((Dog *)(obj[i]))->getIdea(i) << std::endl;
        else{
            std::cout << ((Cat *)(obj[i]))->getIdea(i) << std::endl;
        }
        j++;
    }
    for (int i = 0; i < ARRAYSIZE; i++) {
        delete obj[i];
    }
    delete meta;
    return 0;

}

