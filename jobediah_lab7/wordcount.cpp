/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   08-09-2014
 *   Last modified:  08-09-2014
 *   Filename:       wordcount.cpp
 *
 *   Overview: Calculates the word count and character count of a file.
 *   Input: Text file.
 *   Output: Word count, character count, and character count without spaces.
 *   General Citations:  General syntax structure came from Chapter 1-14
 *   of Absolute c++, Walter Savitch, except where noted
 **************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;

int main()
{
    //Open sample file
    ifstream myfile;
    myfile.open("marktwain.txt");
    
    //Check if file is opened
    if(myfile.fail())
    {
        cout<<"Could not open file."<<endl;
        exit(1);
    }
       
    //Collection of variables to hold word and character counts
    int charCount = 0;
    int charCount2 = 0;
    int wordCount = 0;
    char whitespace;
    
    //While loop runs through each character in file
    while(! myfile.eof())
    {
        char character;
        
        myfile.get(character);
        
        //if statement checks if previous character was a white space
        if(!(whitespace == ' ' && character == ' '))
        {
        
        whitespace = character;
        
            //Adds to word count if there is a whitespace
            //Substracts a character count if whitespace
            if(character == ' ' || character == '\n')
            {
                wordCount += 1;
                charCount2 -= 1;
            }
        
            if(character == '\n')
            {
                charCount -= 1;
            }
        
            charCount2 += 1;
            
        }
        
        charCount += 1;
    }
       
    //Outputs results to screen
    cout<<"The word count is: "<<wordCount -1 <<endl;
    cout<<"The character count is:"<<charCount<<endl;
    cout<<"The character count without spaces is:"<<charCount2<<endl;
    
    myfile.close();
    
    return 0;
}