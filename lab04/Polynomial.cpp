//
// Created by beni on 10/8/2025.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double coefficients[])
{
    this->capacity = degree+1;
    this->coefficients = new double [capacity];

    for (int i=0; i<capacity ; ++i)
    {
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::~Polynomial()
{
    if (coefficients != nullptr)
    {
        delete[]coefficients;
    }
}

ostream &operator<<(ostream &out, const Polynomial &what)
{
    for(int i=0;i<what.capacity-1;++i)
    {
        out << what.coefficients[i] << "x^" << (what.capacity-1-i) << "+";
    }

    out << what.coefficients[what.capacity-1] << endl;
    return out;
}

double Polynomial::evaluate(double x) const
{
    double v = this->coefficients[0];

    for(int i=1;i<this->capacity;++i)
    {
        v= v*x + this->coefficients[i];
    }
    return v;
}

//Masolo konstruktor
Polynomial::Polynomial(const Polynomial& that)
{
    this->capacity = that.capacity;
    this->coefficients = new double[capacity];

    for(int i=0;i<capacity;++i)
    {
        this->coefficients[i] = that.coefficients[i];
    }
}

//derivalas
Polynomial Polynomial::derivative() const
{
    if (capacity <=1)
    {
        double zero= 0;
        return Polynomial(0,&zero);
    }

    int newDegree = capacity -2;  //hanyadik hatvanyrol kezdunk
    double *newCoeff = new double[newDegree+1];

    for (int i=0;i<=newDegree; ++i)
    {
        newCoeff[i] = coefficients[i]*(capacity-i-1);
    }

    Polynomial result(newDegree, newCoeff);
    delete[] newCoeff;
    return result;
}

Polynomial operator-(const Polynomial& a)
{
    double *newCoeff = new double[a.capacity];
    for (int i=0;i< a.capacity ;++i)
    {
        newCoeff[i] = -a.coefficients[i];
    }
    Polynomial result (a.capacity-1,newCoeff);
    delete[] newCoeff;
    return result;
}

Polynomial operator+(const Polynomial& a, const Polynomial& b)
{
    int maxCap=max(a.capacity,b.capacity);
    int diffA = maxCap - a.capacity;
    int diffB = maxCap - b.capacity;

    double *newCoeff = new double[maxCap];

    for(int i=0; i<maxCap;++i)
    {
        double ca,cb;
        if(i - diffA < 0){ca= 0;}else{ca = a.coefficients[i-diffA];}
        if(i - diffB < 0){cb= 0;}else{cb = b.coefficients[i-diffB];}
        newCoeff[i]= ca+cb;
    }

    Polynomial result(maxCap-1,newCoeff);
    delete[] newCoeff;
    return  result;

}


