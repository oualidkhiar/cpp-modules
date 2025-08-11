/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:37:32 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/11 17:52:01 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
protected:
    bool GateFlag;
public:
    ScavTrap();
    ScavTrap(std::string name);
    ~ScavTrap();
    ScavTrap(const ScavTrap& cp);
    ScavTrap& operator=(const ScavTrap& other);

    void attack( std::string name );
    void guardGate();
    
    void GetStatus(void);

};

#endif
