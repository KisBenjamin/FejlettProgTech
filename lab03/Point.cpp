//
// Created by beni on 10/1/2025.
//

#include "Point.h"
#include <cmath>

Point::Point(int x, int y)
{
    if((x >= 0 && x<= M) && (y >= 0 && y<= M))
    {
        this->x=x;
        this->y=y;
    }

}

int Point::getX() const
{
    return this->x;
}
int Point::getY() const
{
    return this->y;
}

double Point::distanceTo(const Point& point) const
{
    int dx = this->x - point.getX();
    int dy = this->y - point.getY();
    return sqrt(dx*dx + dy*dy);
}
