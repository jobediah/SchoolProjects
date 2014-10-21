/*************************************************************
 *   Author:         Jody Hansen
 *   Date created:   08-24-2014
 *   Last modified:  08-28-2014
 *   Filename:       classFighter.cpp
 *
 *   Overview: This program simulates a combat scene between two fighters.
 *   Input: Choice of fighters.
 *   Output: Outputs fighters health status after attack.
 *   General Citations:  General syntax structure came from Chapter 1-14
 *   of Absolute c++, Walter Savitch, except where noted
 **************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "classFighter.h"

using std::cout;
using std::cin;
using std::endl;


Fighter::Fighter() : attack(0), defend(0), armor(0), strength(0){}

Fighter::Fighter(const int& attackSet, const int& defendSet, const int& armorSet, const int& strengthSet, const string& nameSet) : attack(attackSet), defend(defendSet), armor(armorSet), strength(strengthSet), name(nameSet) {}

int Fighter::getStrength() const
{
    return strength;
}

string Fighter::getName() const
{
    return name;
}

void Fighter::setStrength(int strengthpts)
{
    strength = strengthpts;
}

void Fighter::calculateDamage(Fighter* creature1, Fighter* creature2)
{
    
    creature1->strength = creature1->strength - creature2->attack + creature1->armor + creature1->defend;
    //cout<<"strength point"<<creature1->strength<<endl;
    
}

