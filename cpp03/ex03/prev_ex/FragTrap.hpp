/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:47:20 by oukhiar           #+#    #+#             */
/*   Updated: 2025/08/11 17:26:51 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: virtual public ClapTrap {

public:

    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& cp);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void attack( std::string target );
    void highFivesGuys(void);
    void GetStatus( void );

};



#endif