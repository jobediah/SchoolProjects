/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   07-05-2014
 *   Last modified:  07-06-2014
 *   Filename:       Game_of_Life.h
 *
 *   Overview: This program recapitulates John Conway's Game of Life.
 *   Input: Choice of starting configuration and number of generations.
 *   continue game.
 *   Output: Outputs 80X22 game of life
 *   General Citations:  General syntax structure came from Chapter 1-5
 *   of Absolute c++, Walter Savitch.
 **************************************************************/
#include <iostream>
#ifndef HANSEN_Game_of_Life
#define HANSEN_Game_of_Life

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class GameOfLife
{
public:
    void gameBoard();
    // Fills the gameboard array and generates a starting configuration.
    void copyBoard();
    // Copys the board to another temporary gameboard
    void printBoard();
    // Outputs the game board to the console
    void checkInput(std::string &check);
    // Checks user input to determine if it's a valid choice for a starting configuraton
    void checkInput(int &check);
    // Checks user input to determine if it's a valid choice for generation number
    void generations();
    //Calculates if a cell space should live, die, or populate
    std::string input1;
    //Variable to hold user specified starting configuration
    int numberGenerations;
    //Varibale to hold user specified number of generations
    
private:
    char gameboard1[32][90];
    //Holds original generation version of gameboard for reference
    char gameboard2[32][90];
    //Holds version of gameboard to be modified
};

#endif