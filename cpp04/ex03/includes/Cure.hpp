/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 08:56:55 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 12:03:23 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
public:
    Cure();
    Cure(const Cure& cp);
    Cure& operator=(const Cure& other);
    ~Cure();
    AMateria* clone() const;
    void  use(ICharacter& target);
};

#endif