/*************************************************************
*   Author:         Jody Hansen
*   Date created:   07-03-2014
*   Last modified:  07-05-2014
*   Filename:       Game_of_Life.cpp
*   
*   Overview: This program recapitulates John Conway's Game of Life.
*   Input: Choice of starting configuration and number of generations.
*   continue game.
*   Output: Outputs 80X22 game of life 
*   General Citations:  General syntax structure came from Chapter 1-5 
*   of Absolute c++, Walter Savitch.
**************************************************************/

#include <iostream>
#include "Game_of_Life.h"

using std::cout;
using std::cin;
using std::endl;

void GameOfLife::gameBoard()
{
    for(int j = 0; j < 32; j++)
    {
        for(int k = 0; k < 90; k++)
        {
            gameboard1[j][k] = ' ';
        }
    }
    
    if(input1 == "Boat")
    {
        gameboard1[16][50] = '*';
        gameboard1[16][51] = '*';
        gameboard1[17][50] = '*';
        gameboard1[17][53] = '*';
        gameboard1[18][51] = '*';
    }
    
    else if(input1 == "Queenbee")
    {
        gameboard1[16][49] = '*';
        gameboard1[16][50] = '*';
        gameboard1[17][51] = '*';
        gameboard1[18][52] = '*';
        gameboard1[19][52] = '*';
        gameboard1[20][52] = '*';
        gameboard1[21][51] = '*';
        gameboard1[22][50] = '*';
        gameboard1[22][49] = '*';
    }
    
    else if(input1 == "Acorn")
    {
        gameboard1[16][49] = '*';
        gameboard1[17][51] = '*';
        gameboard1[18][48] = '*';
        gameboard1[18][49] = '*';
        gameboard1[18][52] = '*';
        gameboard1[18][53] = '*';
        gameboard1[18][54] = '*';
    }
    
    else if(input1 == "Line")
    {
        gameboard1[16][49] = '*';
        gameboard1[16][51] = '*';
        gameboard1[16][50] = '*';
    }
    
    
    else
    {
        gameboard1[16][50] = '*';
        gameboard1[16][51] = '*';
        gameboard1[17][49] = '*';
        gameboard1[17][52] = '*';
        gameboard1[18][50] = '*';
        gameboard1[18][52] = '*';
        gameboard1[19][51] = '*';
    }
}

void GameOfLife::copyBoard()
{
    for(int j = 0; j < 32; j++)
    {
        for(int k = 0; k < 90; k++)
        {
            gameboard2[j][k] = gameboard1[j][k];
        }
    }
    
}

void GameOfLife::printBoard()
{
    cout<<endl;
    cout<<"#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#"<<endl;
    for(int j = 5; j < 27; j++)
    {
        for(int k = 5; k < 85; k++)
        {
            cout<<gameboard1[j][k]<<" ";
            
        }
        cout<<"\n";
    }
    cout<<"#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#"<<endl;
    cout<<endl;
}

void GameOfLife::checkInput(std::string &check)
{
    while(!(input1=="Acorn" || input1=="Boat" || input1=="Queenbee" || input1=="Loaf" || input1=="Line"))
    {
        cout<<"That wasn't a valid input. Please enter a starting configuration."<<endl;
        cin>>input1;
    }
    
}

void GameOfLife::checkInput(int &check)
{
    while(cin.fail() || !(check > 0 && check < 1001))
    {
        cin.fail();
        cin.clear();
        cin.ignore(9999,'\n');
        cout<<"That wasn't a valid input. Please enter 1-1000."<<endl;
        cin>>check;
    }
}

void GameOfLife::generations()
{
    for(int j = 1; j < 31; j++)
    {
        for(int k = 1; k < 89; k++)
        {
            if(gameboard2[j][k] == '*')
            {
                int i = 0;
                if(gameboard2[j-1][k-1] == '*'){i += 1;}
                if(gameboard2[j-1][k] == '*'){i += 1;}
                if(gameboard2[j-1][k+1] == '*'){i += 1;}
                if(gameboard2[j][k-1] == '*'){i += 1;}
                if(gameboard2[j][k+1] == '*'){i += 1;}
                if(gameboard2[j+1][k-1] == '*'){i += 1;}
                if(gameboard2[j+1][k] == '*'){i += 1;}
                if(gameboard2[j+1][k+1] == '*'){i += 1;}
                
                if(i < 2 || i > 3)
                {
                    gameboard1[j][k] = ' ';
                }
            }
            
            else
            {
                int i = 0;
                if(gameboard2[j-1][k-1] == '*'){i += 1;}
                if(gameboard2[j-1][k] == '*'){i += 1;}
                if(gameboard2[j-1][k+1] == '*'){i += 1;}
                if(gameboard2[j][k-1] == '*'){i += 1;}
                if(gameboard2[j][k+1] == '*'){i += 1;}
                if(gameboard2[j+1][k-1] == '*'){i += 1;}
                if(gameboard2[j+1][k] == '*'){i += 1;}
                if(gameboard2[j+1][k+1] == '*'){i += 1;}
                
                if(i == 3)
                {
                    gameboard1[j][k] = '*';
                }
                
            }
        }
    }
    
    copyBoard();
    
}
