/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   08-24-2014
 *   Last modified:  08-28-2014
 *   Filename:       subclassGoblin.cpp
 *
 *   Overview: This program simulates a combat scene between two fighters.
 *   Input: Choice of fighters.
 *   Output: Outputs fighters health status after attack.
 *   General Citations:  General syntax structure came from Chapter 1-14
 *   of Absolute c++, Walter Savitch, except where noted
 **************************************************************/

#include <iostream>
#include <cstdlib>
#include "classFighter.h"
#include "subclassGoblin.h"

using std::cout;
using std::cin;
using std::endl;

Goblin::Goblin() : Fighter(diceRoll1(), diceRoll2(),3, 8, "Goblin") {}

int Goblin::diceRoll1() const
{
    int number;
    number = (2 * 6) -1;
    
    int diceRollResult;
    diceRollResult = rand() % number + 2;
    
    return diceRollResult;
}

int Goblin::diceRoll2() const
{
    int number;
    number = (1 * 6) -1;
    
    int diceRollResult;
    diceRollResult = rand() % number + 2;
    
    return diceRollResult;
}

