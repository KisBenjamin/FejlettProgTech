//
// Created by beni on 9/24/2025.
//

#include "Point.h"
#include <cmath>
#include <set>
#include <iostream>
using namespace  std;
Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    }
    else {
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print() const
{
    cout << "("<< getX() << "," << getY() << ")"<< endl;
}

double distance(const Point& a, const Point& b)
{
    int dx = a.getX()-b.getX();
    int dy = a.getY()-b.getY();
    return sqrt(dx*dx + dy*dy);

}
bool isSquare(const Point& a, const Point& b, const Point& c, const Point&d)
{
    set<double> tav;
    tav.insert(distance(a,b));
    tav.insert(distance(a,c));
    tav.insert(distance(a,d));
    tav.insert(distance(b,c));
    tav.insert(distance(b,d));
    tav.insert(distance(c,d));

    if (tav.size() == 2)
    {
        return true;
    }
    return false;
}
