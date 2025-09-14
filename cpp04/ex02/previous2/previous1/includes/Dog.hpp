/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:41:01 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 16:09:06 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "../../includes/Brain.hpp"

class Dog: public Animal {
private:
    Brain *B;
public:
    Dog();
    Dog(const Dog& cp);
    Dog& operator=(const Dog& other);
    ~Dog();
    
    void makeSound( void ) const;
    void setIdea(std::string idea, int index);
    std::string getIdea(int index);
};


#endif