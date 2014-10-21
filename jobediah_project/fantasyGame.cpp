/*************************************************************
*   Author:         Jody Hansen
*   Date created:   08-24-2014
*   Last modified:  08-29-2014
*   Filename:       fantasyGame.cpp
*   
*   Overview: This program simulates a combat tournament between fighters of 
*   two teams.
*   Input: Choice of fighters.
*   Output: Outputs the winners of the tournament.
*   General Citations:  General syntax structure came from Chapter 1-16
*   of Absolute c++, Walter Savitch, except where noted
**************************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>
#include "classFighter.h"
#include "subclassGoblin.h"
#include "subclassBarbarian.h"
#include "subclassReptile.h"
#include "subclassBluemen.h"
#include "subclassMaryLittle.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void checkInput(int& check);
//Checks if user entered the correct data type and if it's 0<check<6.
//Input is an integer variable named playerA or playerB
//Output: Prompts user to enter a correct number if entry is invalid.

void checkInput2(int& check);
//Checks if user entered the correct data type and if it's 0<check<2.
//Input is an integer variable named maryChoice or movement
//Output: Prompts user to enter a correct number if entry is invalid.


int main()
{
    
    srand(time(NULL));
    
    //Collection of vectors to hold the player 1 and 2s choice of fighters and
    //two vectors to hold the defeated fighters names and strength points.
    vector<Fighter*> team1;
    vector<Fighter*> team2;
    vector<string> winners;
    vector<int> health;
    
    int playerA;        //Stores user input of player1 choice
    int playerB;        //Stores user input of player2 choice
    
    //Prompt user1 to choose a character.
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Welcome to fantasy combat."<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    
    cout<<"Player 1, please choose three characters from the list."<<endl;
    cout<<"For Goblin, press 1."<<endl;
    cout<<"For Barbarian, press 2."<<endl;
    cout<<"For Reptile People, press 3."<<endl;
    cout<<"For Blue Men, press 4."<<endl;
    cout<<"For Mary Little Lamb, press 5."<<endl;
    cout<<"Press return after each selection."<<endl;
    
    //Takes in input for character choice and validates if it's a viable option.
    //Adds fighters to vector.
    for(int i = 0; i < 3; i++)
    {
        cin>>playerA;
        checkInput(playerA);
        
        switch(playerA)
        {
            case 1:
                team1.push_back(new Goblin);
                break;
            case 2:
                team1.push_back(new Barbarian);
                break;
            case 3:
                team1.push_back(new Reptile);
                break;
            case 4:
                team1.push_back(new Bluemen);
                break;
            case 5:
                team1.push_back(new MaryLittle);
                break;
        }

        cin.clear();
        cin.ignore(9999,'\n');
    }
    
    //Prompt user1 to choose a character.
    cout<<"Player 2, please choose your character from the list."<<endl;
    cout<<"For Goblin, press 1."<<endl;
    cout<<"For Barbarian, press 2."<<endl;
    cout<<"For Reptile People, press 3."<<endl;
    cout<<"For Blue Men, press 4."<<endl;
    cout<<"For Mary Little Lamb, press 5."<<endl;
    cout<<"Press return after each selection."<<endl;
    
    //Takes in input for character choice and validates if it's a viable option.
    //Adds fighters to vector.
    for(int j = 0; j < 3; j++)
    {
        cin>>playerB;
        checkInput(playerB);
        
        switch(playerB)
        {
            case 1:
                team2.push_back(new Goblin);
                break;
            case 2:
                team2.push_back(new Barbarian);
                break;
            case 3:
                team2.push_back(new Reptile);
                break;
            case 4:
                team2.push_back(new Bluemen);
                break;
            case 5:
                team2.push_back(new MaryLittle);
                break;
        }
    }
    
    int count = 0;          //Used to count loops in while loop
    string newPlayers;      //Used to id if fighters have change in while loop.
    Fighter* player;
    
    //Main while loop where the tournament occurs, calls calculatedamage function
    //to determine the damage inflicted by the other player.
    while(team1.size() > 0 && team2.size() > 0)
    {
        if(newPlayers != team1[0]->getName())
        {
            cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*\n";
            cout<<"In the ring we have from:"<<endl;
            cout<<"Team #1: "<<team1[0]->getName()<<endl;
            cout<<"Team #2: "<<team2[0]->getName()<<"\n";
            cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~~*~*~*~*\n\n";
        }
        
        player->calculateDamage(team2[0], team1[0]);
        
        newPlayers = team1[0]->getName();
        
        //If statement checks if fighters have been fighing for 20 loops, if
        //so then one of the players is randomly assigned strenght pts of 0
        if(count > 10)
        {
            team2[0]->setStrength(0);
            count = 0;
        }
        count += 1;
        
        //If statements check if strength is 0 or below, if so the fighter is
        //removed and the other team player is moved to the end of the list.
        if(team2[0]->getStrength() < 1)
        {
            cout<<"Sorry player2, your fighter "<<team1[0]->getName()<<" didn't survive."<<endl;
            winners.push_back("Player2 "+team2[0]->getName());
            cout<<"Your player had: "<<team2[0]->getStrength()<<" health points.\n\n";
            health.push_back(team2[0]->getStrength());
            team2.erase(team2.begin());
            team1.push_back(team1[0]);
            team1.erase(team1.begin());
        }
        
        if(team1.size() > 0 && team2.size() > 0)
        {
            player->calculateDamage(team1[0], team2[0]);
            
            if(count > 10)
            {
                team1[0]->setStrength(0);
                count = 0;
            }
            
            if(team1[0]->getStrength() < 1)
            {
                cout<<"Sorry player1, your fighter "<<team2[0]->getName()<<" didn't survive."<<endl;
                winners.push_back("Player1 "+team1[0]->getName());
                cout<<"Your player had: "<<team1[0]->getStrength()<<" health points.\n\n";
                health.push_back(team1[0]->getStrength());
                team1.erase(team1.begin());
                
                team2.push_back(team2[0]);
                team2.erase(team2.begin());
            }
        }
    }
    
    count = 0;
    
    //While loop makes remaining players on team1 fight each other.
    while(team1.size() > 1)
    {
        player->calculateDamage(team1[0], team1[1]);
        
        if(count > 10)
        {
            team1[0]->setStrength(0);
            count = 0;
        }
        
        if(team1[0]->getStrength() < 1)
        {
            winners.push_back("Player1 "+team1[0]->getName());
            health.push_back(team1[0]->getStrength());
            team1.erase(team1.begin());
        }
        
        if(team1.size() > 1)
        {
            player->calculateDamage(team1[1], team1[0]);
            if(team1[1]->getStrength() < 1)
            {
                winners.push_back("Player1 "+team1[1]->getName());
                health.push_back(team1[1]->getStrength());
                team1.erase(team1.begin()+1);
            }
        }
        
        count += 1;
    }
    
    //while loop removes the remaining team1 fighter.
    while(team1.size() == 1)
    {
        winners.push_back("Player1 "+team1[0]->getName());
        health.push_back(team1[0]->getStrength());
        team1.erase(team1.begin());
    }
      
    count = 0;
    
    //While loop makes remaining players on team1 fight each other.
    while(team2.size() > 1)
    {
        player->calculateDamage(team2[0], team2[1]);

        if(count > 10)
        {
            team2[0]->setStrength(0);
            count = 0;
        }
        
        if(team2[0]->getStrength() < 1)
        {
            winners.push_back("Player2 "+team2[0]->getName());
            health.push_back(team2[0]->getStrength());
            team2.erase(team2.begin());
        }
        
        if(team1.size() > 1)
        {
            player->calculateDamage(team2[1], team2[0]);
            
            if(team2[1]->getStrength() < 1)
            {
                winners.push_back("Player2 "+team2[1]->getName());
                health.push_back(team2[1]->getStrength());
                team2.erase(team2.begin()+1);
            }
        }
        
        count += 1;
    }
    
    //while loop removes the remaining team1 fighter.
    while(team2.size() == 1)
    {
        winners.push_back("Player2 "+team2[0]->getName());
        health.push_back(team2[0]->getStrength());
        team2.erase(team2.begin());
    }
    
    int order = 1;
    
    cout<<"The winners are: "<<endl;
    
    //Container iterators for name and strength pts vectors.
    vector<string>::reverse_iterator q;
    vector<int>::reverse_iterator t = health.rbegin();
    
    //Iterators through fighters. 
    for(q = winners.rbegin(); q != winners.rend(); q++)
    {
        cout<<order<<" "<<*q<<" with a health of: "<<*t<<endl;
        order += 1;
        t++;
    }
    
    return 0;
}

void checkInput(int& check)
{
    while(cin.fail() || check < 1 || check > 5)
    {
    cin.fail();
    cin.clear();
    cin.ignore(9999,'\n');
    cout<<"That wasn't a valid input. Try again."<<endl;
    cin>>check;
    }
}

void checkInput2(int& check)
{
    while(cin.fail() || check < 1 || check > 2)
    {
        cin.fail();
        cin.clear();
        cin.ignore(9999,'\n');
        cout<<"That wasn't a valid input. Try again."<<endl;
        cin>>check;
    }
}

