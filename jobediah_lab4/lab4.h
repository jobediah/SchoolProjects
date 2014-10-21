/*************************************************************
*   Author:         Jody Hansen
*   Date created:   07-15-2014
*   Last modified:  07-19-2014
*   Filename:       lab4.h
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

#ifndef Hansen_lab4
#define Hansen_lab4

using std::cout;
using std::endl;
using std::cin;
using std::vector;

class Vector2D
{
public:
    Vector2D(int row1, int col2);
    Vector2D();
    void setupxy(int setrows, int setcols);
    //Creates the 2D vector
    int getxy(int getrows, int getcols) const;
    //Returns the value at a specific location of the vector
    void addxy(int row, int col, int number);
    //Allows the user to add a value to the 2D vector
    void checkInput(int &check);
    //Checks that the user entered a number
    const Vector2D operator *(const Vector2D& vector1) const;
    const Vector2D operator +(const Vector2D& vector2) const;
private:
    vector < vector <int> > v;
    int x;
    int y;
    
};

#endif

