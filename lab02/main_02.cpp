#include <iostream>
#include <fstream>
#include "Point.h"
using namespace std;

int main(int argc, char** argv) {
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    p1.print();
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    cout << "Distance p1,p2: " << distance(p1,p2) <<endl;
    cout << (isSquare(Point(0,0),Point(2,0),Point(2,2),Point(0,2)) == true ? "True its a Square" : "False its not a Square");
    cout << endl;

    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    delete pp1;
    delete pp2;

    ifstream ifs("data/input.txt");
    if (!ifs)
    {
        cout <<"FIle not found !" << endl;
        exit(404);
    }
    int x,y;
    Point points[4];
    int index=-1;
    while( ifs >> x >> y)
    {
        points[++index]=Point(x,y);
        if (index==3)
        {
            points[0].print();
            points[1].print();
            points[2].print();
            points[3].print();
            cout << (isSquare(points[0],points[1],points[2],points[3]) == true ? "True its a Square" : "False its not a Square"); cout << endl;
            index=-1;
        }
    }
 return 0;
}
