/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:37:32 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/07 18:43:11 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./prev_ex/ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    private:
        
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
};

#endif