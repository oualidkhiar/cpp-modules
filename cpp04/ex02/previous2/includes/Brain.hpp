/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:48:25 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/29 14:33:56 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define NBIDEAS 100

class Brain {
    private:
        std::string ideas[NBIDEAS];
    public:
        Brain();
        Brain(const Brain& cp);
        Brain& operator=(const Brain& other);
        ~Brain();

        void setIdea(std::string idea, int index);
        std::string getIdea(int index);
};

#endif