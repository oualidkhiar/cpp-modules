/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:14:16 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/12 14:03:20 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPPP
# define DIAMONDTRAP_HPPP

#include "./prev_ex/FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
private:
    std::string DName;
public:

    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& cp);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void whoAmI();
    void attack(std::string target);
    void GetStatus( void );

};




#endif