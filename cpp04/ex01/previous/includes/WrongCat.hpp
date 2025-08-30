/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:02:02 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 16:09:39 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& cp);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

    void makeSound( void ) const;
    std::string getType() const;
};


#endif