/*************************************************************
*   Author:         Jody Hansen
*   Date created:   07-15-2014
*   Last modified:  07-19-2014
*   Filename:       main.cpp
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

int main()
{
    
    int rows, cols, number;
    cout<<"Enter the number of rows:"<<endl;
    cin>>rows;
    cout<<"Enter the number of columns:"<<endl;
    cin>>cols;
    cout<<"Enter your values for your first matrix:"<<endl;
    
    //Sets the x, y values to the number of rows and columns
    Vector2D a(rows, cols);
    
	a.setupxy(rows, cols);
    
	//User fills the first vector
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
        {
            cout<<"Enter the number for row, "<<i+1<<" and column, "<<j+1<<endl;
            cin>>number;
            a.checkInput(number);
            a.addxy(i,j,number);
        }
    cout<<endl;
    
    cout<<"Enter your values for your second matrix:"<<endl;
    
    Vector2D b;
    b.setupxy(rows,cols);
    
	//User fills the second vector
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
        {
            cout<<"Enter the number for row, "<<i+1<<" and column, "<<j+1<<endl;
            cin>>number;
            b.checkInput(number);
            b.addxy(i,j,number);
        }
    cout<<endl;

    //Outputs the first vector to the user
    cout<<"Here's your first matrix:"<<endl;
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<a.getxy(i,j)<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    
    //Outputs the second vector to the user
    cout<<"Here's your second matrix:"<<endl;
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<b.getxy(i,j)<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    
    Vector2D ab;
    
    // Calculates the product of two vectors
    ab = a*b;
    cout<<"The product of your two vectors is:"<<endl;
    
    for(int i = 0; i < rows; i++)
    {
        cout<<ab.getxy(i,0)<<" ";
    }
    
    cout<<endl;
    
    // Calculates the addition of two vectors
    Vector2D asumb;
    asumb = a+b;
    cout<<"The sum of your two vectors is:"<<endl;
    
    for(int i = 0; i < rows; i++)
    {
        cout<<asumb.getxy(i,0)<<" ";
    }
    
    cout<<endl;

    return 0;
}

