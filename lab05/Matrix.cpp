//
// Created by beni on 10/27/2025.
//

#include "Matrix.h"
#include <iostream>
#include <random>
#include <stdexcept>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
using namespace std;


Matrix::Matrix(int rows, int cols)
    : mRows(rows), mCols(cols), mElements(rows * cols,0.0)
{
    if(rows <= 0 || cols <=0)
    {
        throw out_of_range("Matrix sixe pozitiv kell legyen!");
    }
}

Matrix::Matrix(const Matrix& other)
    : mRows(other.mRows), mCols(other.mCols), mElements(other.mElements)
{
}

Matrix::Matrix(Matrix&& other) noexcept
    : mRows(other.mRows), mCols(other.mCols), mElements(move(other.mElements))
{
    other.mRows = 0;
    other.mCols = 0;
}

//copy assigment
Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        mRows = other.mRows;
        mCols = other.mCols;
        mElements = other.mElements;
    }
    return *this;
}

// Move assignment
Matrix& Matrix::operator=(Matrix&& other) noexcept
{
    if( this!= &other)
    {
        mRows = other.mRows;
        mCols = other.mCols;
        mElements = move(other.mElements);
        other.mRows = 0;
        other.mCols = 0;
    }

    return *this;
}

void Matrix::fillMatrix(double value)
{
    fill(mElements.begin(),mElements.end(), value);
}

