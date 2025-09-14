/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:29:13 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/09/05 15:05:25 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
    std::cout << "constructor for Brain class called" << std::endl;
}

Brain::Brain(const Brain& cp) {
    for (int i = 0; i < NBIDEAS; i++) {
        if (cp.ideas[i].length() != 0)
            this->ideas[i] = cp.ideas[i];
    }
    std::cout << "copy constructor for Brain class called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < NBIDEAS; i++) {
            if (other.ideas[i].length() != 0)
                this->ideas[i] = other.ideas[i];
        }
    }
    std::cout << "copy assignment operator called for Brain class" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "deconstructor for Brain class called" << std::endl;
}

void Brain::setIdea(std::string idea, int index) {
    if (index < NBIDEAS && index >= 0)
        this->ideas[index] = idea;
    else
        std::cout << "invalid index" << std::endl;
}

std::string Brain::getIdea(int index) {
    if (index < NBIDEAS && index >= 0 && ideas[index].length() != 0)
        return this->ideas[index];
    else {
        std::cout << "there is no idea in this index" << std::endl;
        return "";
    }
}
