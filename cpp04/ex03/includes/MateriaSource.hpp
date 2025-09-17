/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:19:27 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/17 12:04:42 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#define MAX_MATERIASRC 4
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
private:
    AMateria *table[MAX_MATERIASRC];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& cp);
    const MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif
