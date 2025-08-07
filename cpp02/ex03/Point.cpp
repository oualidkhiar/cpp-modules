/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:01:14 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/04 10:48:57 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(float x, float y): x(x), y(y) {}

Point::Point(const Point& other): x(other.x) , y(other.y) {}

Point::~Point() {
    std::cout << "destructor called" << std::endl;
}

float Point::getX() const {
    return x.toFloat();
}

float Point::getY() const {
    return y.toFloat();
}
