/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   08-24-2014
 *   Last modified:  08-28-2014
 *   Filename:       subclassBarbarian.h
 *
 *   Overview: This program simulates a combat scene between two fighters.
 *   Input: Choice of fighters.
 *   Output: Outputs fighters health status after attack.
 *   General Citations:  General syntax structure came from Chapter 1-15
 *   of Absolute c++, Walter Savitch, except where noted
 **************************************************************/

#include <iostream>
#include "classFighter.h"

#ifndef Hansen_subclassBarbarian
#define Hansen_subclassBarbarian

class Barbarian : public Fighter
{
public:
    //Constructor function initializes attack, defend, armor, and strength variables
    Barbarian();
    //Calls random generate to set attack and defend variables according to the
    //number of dice rolls.
    int diceRoll1() const;
    //Sets parent attack variable to given random number range
    int diceRoll2() const;
    
};

#endif