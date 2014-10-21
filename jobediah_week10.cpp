/*************************************************************
*   Author:         Jody Hansen
*   Date created:   06-01-2014
*   Last modified:  06-01-2014
*   Filename:       Week10_Project_extra.cpp
*   
*   Overview: This program will let the user choose either the number, word, or phrase 
*   game to play. Each game is its own class.
*   Input: y/n to continue playing, game choice, guesses or number, words, letters, or 
*   phrase.
*   Output: Number, word, or phrase game.
*
*   General Citations:  General syntax structure came from Chapter 1-13 of
*   Absolute c++, Walter Savitch.
**************************************************************/
 
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class NumberGame
{
public:
    void runGame();         //Starts game
    void pickNumber();      //Randomly generates a secret number
    void checkInput(int check);      //Checks if user input is a valid number
    bool checkIfCorrect();  //Checks if user guessed the secret number
    void checkRange();      //Checks if user number is too low or too high
    void outputRange();     //Outputs a narrowed range for user to guess from
    
private:
    int secretNumber;       //Holds the number user will guess
    int low_range;          //Holds the lower end of range
    int high_range;         //Holds the higer end of range
    int guesses;            //Holds the amount of guesses the user has
    int input;              //Holds the user's input
    int number;             //Sets the random number generator range
};

class WordGame
{
public:
    void runGame();         //Starts game
    void pickWord();        //Picks a word from a list
    void checkInput();      //Checks if user inputted something
    bool checkIfCorrect();  //Checks if user guessed the secret word
    void hideLetters();     //Converts the word so that it contains '-' characters
    void giveHints();       //Takes the user's letter guess and reveals it in the string
private:
    string word;            //Holds the word to be guessed
    string input;           //Holds user input
    int number;             //Holds a random number to choose word from list
    int guesses;            //Holds the amount of guesses the user has
    string tempWord;        //Holds a version of the word but with '-' characters
    char letter;            //Holds the user's letter guesss
    
};

class PhraseGame
{
public:
    void runGame();         //Starts game
    void pickPhrase();        //Picks a word from a list
    void checkInput();      //Checks if user inputted something
    bool checkIfCorrect();  //Checks if user guessed the secret word
    void hideLetters();     //Converts the word so that it contains '-' characters
    void giveHints();       //Takes the user's letter guess and reveals it in the string
private:
    string phrase;            //Holds the word to be guessed
    string input;           //Holds user input
    int guesses;            //Holds the amount of guesses the user has
    string tempPhrase;        //Holds a version of the word but with '-' characters
    char letter;            //Holds the user's letter guesss

};

void checkInput(string &answer);
/*  Description: This function checks to see if user entered a valid choice.
    Parameters: user input of a string.
    Output: It cotinues to ask for input until it is either a number, a word,
    or a phrase. */

int main()
{
    char answer2;
    
    // do/while loop to run until user says to stop to playing the game.
    do
    {
        // Create class variables
        NumberGame playNumber;
        WordGame playWord;
        PhraseGame playPhrase;
        
        string answer;
        
        // Prompt user to choose game
        cout<<"Let's play a game"<<endl;
        cout<<"Choose either the number, word, or phrase game. (enter number, word or phrase)"<<endl;
        
        getline(cin, answer);
        
        //Check if user picked one the available games
        checkInput(answer);
        
        //If/else statement to match user's choice with appropriate game
        if(answer == "number")
        {
            playNumber.runGame();
        }
        
        else if(answer == "word")
        {
            playWord.runGame();
        }
    
        else
        {
            playPhrase.runGame();
        }
        
        cout<<"Do you want to play again? (y/n)"<<endl;
        cin>>answer2;
        
        cin.clear();
        cin.ignore();
        
    }while(answer2 == 'Y'|| answer2 == 'y');
    
    return 0;
}

void NumberGame::runGame()
{
    pickNumber();
    
    guesses = 3;
    number = 20;
    
    for(int i = 0; i < 3; i++)
    {
        cout << "Please choose a whole number from 1 to 100: \n";
        cin >> input;
        
        checkInput(input);
    
        if(checkIfCorrect())
        {
            cout<<"That was the correct guess!"<<endl;
            break;
        }
        
        else
        {
            checkRange();
            guesses -= 1;
            if(guesses > 0)
            {
                cout<<"You have"<<" "<<guesses<<" "<<"guesses remaining."<<endl;
                outputRange();
            }
        }
        
        if(guesses == 0)
        {
            cout<<"Thanks for tyring. The number was:"<<" "<<secretNumber<<endl;
        }
        
        number -= 10;
    }
    
}

void NumberGame::pickNumber()
{
    srand(time(NULL));
    secretNumber = rand()%101;
}

void NumberGame::checkInput(int check)
{
    while(cin.fail() || input < 0 || input > 100)
    {
        cin.fail();
        cin.clear();
        cin.ignore();
        cout<<"That was not a valid input , try agian."<<endl;
        cin>>input;
    }
}

bool NumberGame::checkIfCorrect()
{
    if(input == secretNumber)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

void NumberGame::checkRange()
{
    if(input < secretNumber)
    {
        cout<<"Your guess was too low."<<endl;
    }
    
    else
    {
        cout<<"Your guess was too high."<<endl;
    }

}

void NumberGame::outputRange()
{
    srand(time(NULL));
    low_range = secretNumber - (rand()%10 + number);
    
    if(low_range < 0)
    {
        low_range = 0;
    }
    
    high_range = (rand()%10 + number) + secretNumber;
    if(high_range > 100)
    {
        high_range = 100;
    }

    cout<<"Try between"<<" "<<low_range<<" "<<"and"<<" "<<high_range<<endl;
}

void WordGame::runGame()
{
    guesses = 3;
    
    pickWord();
    hideLetters();
    
    for(int i = 0; i < 3; i++)
    {
        // Prompts user to enter a number.
        cout << "Please guess a word. \n";
        getline(cin, input);
        
        checkInput();
        
        if(checkIfCorrect())
        {
            cout<<"That was the correct guess!"<<endl;
            break;
        }
        
        else
        {
            guesses -= 1;
            if(guesses > 0)
            {
                cout<<"You have"<<" "<<guesses<<" "<<"guesses remaining."<<endl;
                cout<<"Guess a letter."<<endl;
                cin.get(letter);
                
                giveHints();
                
                cin.clear();
                cin.ignore();
                
            }
        }
        
        if(guesses == 0)
        {
            cout<<"Thanks for tyring. The number word was:"<<" "<<word<<endl;
        }
    }
}

void WordGame::pickWord()
{
    string array[12] = {"bannana", "balloon", "teacher", "sandwich", "flower", "noodle", "piano", "purple", "rabbit", "vanilla", "donkey", "baseball"};
    
    srand(time(NULL));
    number = rand()%13;
    word = array[number];
}

void WordGame::checkInput()
{
    while(input.empty())
    {
        cout<<"Did you enter a word? Try agian."<<endl;

        getline(cin,input);
    }
}

bool WordGame::checkIfCorrect()
{
    if(input == word)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

void WordGame::hideLetters()
{
    tempWord = word;
    
    for(int i = 0; i < word.length(); i++)
    {
        tempWord.at(i) = '-';
    }
}

void WordGame::giveHints()
{
    for(int i = 0; i < word.length(); i++)
    {
        if(letter == word.at(i))
        {
            tempWord.at(i) = letter;
        }
    }
    cout<<"Your letter fits in here:"<<" "<<tempWord<<endl;
}

void PhraseGame::runGame()
{
    guesses = 5;
    
    pickPhrase();
    hideLetters();
    
    for(int i = 0; i < 5; i++)
    {
        // Prompts user to enter a number.
        cout << "Please guess a phrase. \n";
        getline(cin, input);
        
        checkInput();
        
        if(checkIfCorrect())
        {
            cout<<"That was the correct guess!"<<endl;
            break;
        }
        
        else
        {
            guesses -= 1;
            if(guesses > 0)
            {
                cout<<"You have"<<" "<<guesses<<" "<<"guesses remaining."<<endl;
                cout<<"Guess a letter."<<endl;
                cin.get(letter);
                
                giveHints();
                
                cin.clear();
                cin.ignore();
                
            }
        }
        
        if(guesses == 0)
        {
            cout<<"Thanks for tyring. The number phrase was:"<<" "<<phrase<<endl;
        }
    }
}

void PhraseGame::pickPhrase()
{
    string pronoun[6] = {"the brown fox", "the fat cow", "he", "she", "the snowman", "the kid"};
    string verbs[5] = {"goes", "jumps", "runs", "skips", "hops"};
    
    string locations[5] = {"store", "studio", "park", "home", "school"};

    srand(time(0));
    
    phrase = pronoun[rand()%6] + " " + verbs[rand()%5] + " " + "to the " + locations[rand()%5];
}

void PhraseGame::checkInput()
{
    for(int i = 0; i < phrase.length(); i++)
    {
        if(!(phrase.at(i) == ' ' || isalpha(phrase.at(i))))
        {
            cout<<"Did you enter a phrase? Try agian."<<endl;
            getline(cin,input);
        }
    }
}

bool PhraseGame::checkIfCorrect()
{
    if(input != phrase)
    {
        return false;
    }
    
    return true;
}

void PhraseGame::hideLetters()
{
    tempPhrase = phrase;
    
    for(int i = 0; i < phrase.length(); i++)
    {
        if(isalpha(phrase.at(i)))
        {
            tempPhrase.at(i) = '-';
        }
    }
}

void PhraseGame::giveHints()
{
    for(int i = 0; i < phrase.length(); i++)
    {
        if(letter == phrase.at(i))
        {
            tempPhrase.at(i) = letter;
        }
    }
    cout<<"Your letter fits in here:"<<" "<<tempPhrase<<endl;
}


void checkInput(string &answer)
{
    while(!(answer == "word" || answer == "number" || answer == "phrase"))
    {
        cout<<"That was not one of the options"<<endl;
        
        getline(cin, answer);
    }
}

