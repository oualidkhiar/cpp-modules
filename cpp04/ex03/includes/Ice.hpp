/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 08:40:23 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 12:06:45 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
public:
    Ice();
    Ice(const Ice& cp);
    Ice& operator=(const Ice& other);
    ~Ice();
    AMateria* clone() const;
    void  use(ICharacter& target);
};

#endif