/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:01:18 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/04 10:49:10 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point{
    private:
        const Fixed x;
        const Fixed y;
        Point& operator=(const Point& other);
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        ~Point();
        float getX() const;
        float getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
