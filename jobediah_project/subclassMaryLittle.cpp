/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   08-24-2014
 *   Last modified:  08-28-2014
 *   Filename:       subclassMaryLittle.cpp
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
#include "subclassMaryLittle.h"

using std::cout;
using std::cin;
using std::endl;

MaryLittle::MaryLittle() : Fighter(diceRoll1(), diceRoll2(),4, 16, "MaryLittle") {}


int MaryLittle::diceRoll1() const
{
    int number;
    number = (3 * 6) -1;
    
    int diceRollResult;
    diceRollResult = rand() % number + 2;
    
    return diceRollResult;
}

int MaryLittle::diceRoll2() const
{
    int number;
    number = (1 * 6) -1;
    
    int diceRollResult;
    diceRollResult = rand() % number + 2;
    
    return diceRollResult;
}

