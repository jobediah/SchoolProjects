/*************************************************************
*   Author:         Jody Hansen
*   Date created:   07-15-2014
*   Last modified:  07-19-2014
*   Filename:       lab4.cpp
*
*   Overview: This program will perform vector multiplication and addition.
*   Input:  rompt user to input an integers to fill a vector with user specified
*   number of rows and columns.
*   Output: Results of vector multiplication and addition.
*
*   General Citations:  Syntax structure came from Ch. 1-8 of Absolute c++,
 **************************************************************/
#include <iostream>
#include <vector>
#include "lab4.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;

Vector2D::Vector2D (int row1, int col2): x(row1), y(col2){}

Vector2D::Vector2D () {}

//Syntax for 2D vector came from: http://stackoverflow.com/questions/13936733/inserting-elements-in-multidimensional-vector
void Vector2D::setupxy(int setrows, int setcols)
{
	for(int i = 0; i < setrows; i++)
    {
        vector<int> setrows;
        for(int j = 0; j < setcols; j++)
        {
            setrows.push_back(0);
        }
        v.push_back(setrows);
    }	
}

void Vector2D::addxy(int row, int col, int number)
{
	v[row][col] = number;
}

int Vector2D::getxy(int getrows, int getcols) const
{
    return v[getrows][getcols];
}

void Vector2D::checkInput(int &check)
{
    while(cin.fail())
    {
        cin.fail();
        cin.clear();
        cin.ignore(9999,'\n');
        cout<<"That wasn't a valid input. Try again."<<endl;
        cin>>check;
    }
}


const Vector2D Vector2D::operator *(const Vector2D& vector1) const
{
    Vector2D c;
    
    c.setupxy(x, 1);
    
    for(int i = 0; i < x; i++)
    {
        int number = 0;
        for(int j = 0; j < y; j++)
        {
            number = number + (v[i][j] * vector1.getxy(i,j));
        
        }
        
        c.addxy(i, 0, number);

    }
    
    return c;
}

const Vector2D Vector2D::operator +(const Vector2D& vector2) const
{
    Vector2D d;
    
    d.setupxy(x, 1);
    
    for(int i = 0; i < x; i++)
    {
        int number = 0;
        for(int j = 0; j < y; j++)
        {
            number = number + (v[i][j] + vector2.getxy(i,j));
            
        }
        
        d.addxy(i, 0, number);
        
    }
    
    return d;
}

