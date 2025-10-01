//
// Created by beni on 10/1/2025.
//
#include "Point.h"
#include "PointSet.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
using namespace std;
random_device rd;
mt19937 mt(rd());

PointSet::PointSet(int n) : n(n)
{
    uniform_int_distribution<int> dist(0, M);

    while (points.size() < n)
    {
        int x = dist(mt);
        int y = dist(mt);
        Point p(x,y);


        bool exist = false;
        for (const auto& pt:points)
        {
            if(pt.getX() == p.getX() && pt.getY()==p.getY())
            {
                exist=true;
                break;
            }

        }
        if (!exist)
        {
            points.push_back(p);
        }
    }
    computeDistances();

}

void PointSet::computeDistances()
{
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const
{
    return *max_element(distances.begin(),distances.end());
}

double PointSet::minDistance() const
{
    return *min_element(distances.begin(),distances.end());
}

int PointSet::numDistances() const
{
    return distances.size();
}

void PointSet::printPoints() const
{
    for(auto& pt:points)
    {
        cout << pt.getX() << " " << pt.getY();
    }
}

void PointSet::printDistances() const
{
    for(auto& p:distances)
    {
        cout << p << " ";
    }
}

void PointSet::sortPointsX()
{
    sort(points.begin(),points.end(), [](const Point& a,const Point& b)
    {
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY()
{
    sort(points.begin(),points.end(), [](const Point& a,const Point& b)
    {
        return a.getY() < b.getY();
    });
}

void PointSet::sortDistances()
{
    sort(distances.begin(),distances.end());
}

int PointSet::numDistinctDistances()
{
    set<double> nrDist;
    for(auto& d:distances)
    {
        nrDist.insert(d);
    }

    return nrDist.size();
}




