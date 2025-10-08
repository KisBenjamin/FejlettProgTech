#include <iostream>

#include "Polynomial.h"

using namespace std;
int main() {
    double coeff1[]{1,2,1};
    Polynomial p1(2,coeff1);

    cout << p1;
    cout << p1.derivative() << endl;
    cout << (-p1);

    return 0;
}