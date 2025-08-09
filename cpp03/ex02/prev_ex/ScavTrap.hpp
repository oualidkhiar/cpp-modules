/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:37:32 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/08 14:30:26 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./prev_ex/ClapTrap.hpp"

class ScavTrap : public ClapTrap{
private:
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
