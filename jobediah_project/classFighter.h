/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   08-24-2014
 *   Last modified:  08-28-2014
 *   Filename:       classFighter.h
 *
 *   Overview: This program simulates a combat scene between two fighters.
 *   Input: Choice of fighters.
 *   Output: Outputs fighters health status after attack.
 *   General Citations:  General syntax structure came from Chapter 1-15
 *   of Absolute c++, Walter Savitch, except where noted
 **************************************************************/

#include <iostream>

#ifndef Hansen_classFighter
#define Hansen_classFighter

using std::string;

class Fighter
{
public:
    //Constructor functions
    Fighter();
    Fighter(const int& attackSet, const int& defendSet, const int& armorSet, const int& strengthSet, const string& nameSet);
        
    //Collection of accessor functions to access private values
    int getStrength() const;
    string getName() const;
    
    void setStrength(int strengthpts);

    //Function returns a randomly generated integer corresponding to the
    //number of dice rolls and sides to the dice. 
    void calculateDamage(Fighter* creature1, Fighter* creature2);
    
private:
    int attack;
    int defend;
    int armor;
    int strength;
    string name;
};

#endif