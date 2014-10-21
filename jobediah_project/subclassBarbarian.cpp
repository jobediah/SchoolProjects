/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   08-24-2014
 *   Last modified:  08-28-2014
 *   Filename:       subclassBarbarian.cpp
 *
 *   Overview: This program simulates a combat scene between two fighters.
 *   Input: Choice of fighters.
 *   Output: Outputs fighters health status after attack.
 *   General Citations:  General syntax structure came from Chapter 1-15
 *   of Absolute c++, Walter Savitch, except where noted
 **************************************************************/

#include <iostream>
#include <cstdlib>
#include "classFighter.h"
#include "subclassBarbarian.h"

using std::cout;
using std::cin;
using std::endl;

Barbarian::Barbarian() : Fighter(diceRoll1(), diceRoll2(), 0, 12, "Barbarian") {}


int Barbarian::diceRoll1() const 
{
    int number;
    number = (2 * 6) -1;
    
    int diceRollResult;
    diceRollResult = rand() % number + 2;
    
    return diceRollResult;
}

int Barbarian::diceRoll2() const
{
    int number;
    number = (1 * 6) -1;
    
    int diceRollResult;
    diceRollResult = rand() % number + 2;
    
    return diceRollResult;
}



