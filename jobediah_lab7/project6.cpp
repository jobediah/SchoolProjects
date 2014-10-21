/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   08-09-2014
 *   Last modified:  08-09-2014
 *   Filename:       project6.cpp
 *
 *   Overview: Sorts numbers from two different files.
 *   Input: Input file names and output file name.
 *   Output: One file with sorted numbers.
 *   General Citations:  General syntax structure came from Chapter 1-14
 *   of Absolute c++, Walter Savitch, except where noted
 **************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

void sortFiles(ifstream& file1, ifstream& file2, ofstream& output);
/* Function takes parameters of two files as input and one file as output. 
It will take the numbers from the first files and merge and sort the numbers
into the output file.*/

int main()
{
    //Collection of string variables to hold input and output files
    string fileName1;
    string fileName2;
    string outFileName;
    
    //Prompts for the user to enter file names
    cout<<"Please enter the name of your first file."<<endl;
    
    cin>>fileName1;
    
    cout<<"Please enter the name of your second file."<<endl;
    
    cin>>fileName2;
    
    cout<<"What would you like the output file name to be."<<endl;
    
    cin>>outFileName;
    
    //Open files with checks to make sure they can be opened
    ifstream inputfile1((fileName1+".txt").c_str());
    
    if(inputfile1.fail())
    {
        cout<<"Sorry, could not find the first file."<<endl;
        exit(1);
    }
    
    ifstream inputfile2((fileName2+".txt").c_str());
    
    if(inputfile2.fail())
    {
        cout<<"Sorry, could not find the second file."<<endl;
        exit(1);
    }

    ofstream outputfile((outFileName+".txt").c_str());
    
    if(outputfile.fail())
    {
        cout<<"Sorry, could not find the second file."<<endl;
        exit(1);
    }

    //Function call to merge and sort numbers
    sortFiles(inputfile1, inputfile2, outputfile);
    
    inputfile1.close();
    inputfile2.close();
    outputfile.close();

    return 0;
}

void sortFiles(ifstream& file1, ifstream& file2, ofstream& output)
{
    int number1 = 0;
    int number2 = 0;
    
    file1>>number1;
    file2>>number2;
    
    while(number1 < 10000000 || number2 < 10000000)
    {
        if(number1 <= number2)
        {
            output<<number1<<endl;
            
            if(file1.eof())
            {
                number1 = 100000000;
            }

            else
            {
                file1>>number1;
            }
        }
        
        else
        {
            output<<number2<<endl;
            
            if(file2.eof())
            {
                number2 = 100000000;
            }
            
            else
            {
                file2>>number2;
            }
        }
     }
}