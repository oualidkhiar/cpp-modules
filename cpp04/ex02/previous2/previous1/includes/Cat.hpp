/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:40:53 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 16:06:07 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "../../includes/Brain.hpp"

class Cat: public Animal {
private:
    Brain *B;
public:
    Cat();
    ~Cat();
    Cat(const Cat& cp);
    Cat& operator=(const Cat& other);

    void makeSound( void ) const;
    void setIdea(std::string idea, int index);
    std::string getIdea(int index);

};


#endif
