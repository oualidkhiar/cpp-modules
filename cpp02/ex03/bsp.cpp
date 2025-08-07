/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oukhiar <oukhiar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:01:09 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/08/04 10:46:27 by Oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float MyAbs(float f)
{
    if (f < 0)
        return -f;
    return f;
}

float GetArea(Point a, Point b, Point c)
{
    float result = (a.getX() * (b.getY() - c.getY()) 
                  + b.getX() * (c.getY() - a.getY())
                  + c.getX() * (a.getY() - b.getY())) * 0.5f;
    return MyAbs(result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool result;

    float A = GetArea(a,b,c);
    float A1 = GetArea(point,a,b);
    float A2 = GetArea(point,a,c);
    float A3 = GetArea(point,b,c);
    if (A1 == 0 || A2 == 0 || A3 == 0)
        return false;
    result = (A == A1 + A2 + A3);
    return result;
}
