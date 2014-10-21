/*************************************************************
*   Author:         Jody Hansen
*   Date created:   08-19-2014
*   Last modified:  08-19-2014
*   Filename:       chap17_5.cpp
*
*   Overview: The program uses a circular list to remove the third number in the
*   list.
*   Input: Number of suitors
*   Output: The remaining number will be the suitor that the princess will marry.
*   General Citations:  General syntax structure came from Chapter 1-17
*   of Absolute c++, Walter Savitch, except where noted
**************************************************************/

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

struct ListNode
{
    int number;         //One of two variables, holds the suitor's line number
    ListNode *link;     //Second variable, pointer that will point to next node
};
typedef ListNode *NodePtr;

int main()
{
    //Create the first node of ListNode that contains the end marker
    NodePtr head = NULL;
    head = new ListNode;
    
    //Set the data member variable to 1, set the pointer
    head->number=1;
    head->link = head;
    
    //Create a new instance of the ListNode structure and set member variables
    //to the head Node
    NodePtr pointer;
    pointer = head;
    
    //Variable to take user input
    int suitors;
    
    //Prompt user to input the number of suitors
    cout<<"How many suitors are lined up?"<<endl;
    cin>>suitors;
    
    //Check that the input is valid and more than 0
    while(cin.fail() || suitors < 1)
    {
        cin.fail();
        cin.clear();
        cin.ignore(9999,'\n');
        cout<<"That wasn't a valid input. Try again."<<endl;
        cin>>suitors;
    }
    
    //If/else if statement checks if the user entered 1 or 2
    if(suitors == 1)
    {
        cout<<"Suitor number one wins by default."<<endl;
        exit(1);
    }
    
    else if(suitors == 2)
    {
        cout<<"The suitor who takes the princess's hand is: "<<2<<endl;
        exit(1);
    }
    
    //Create new nodes with the number of suitors, starting after the head node
    for(int i = 2; i < suitors; i++)
    {
        NodePtr Node = new ListNode;
        Node->number = i;
        Node->link = head;
        
        pointer->link = Node;
        pointer = Node;
    }
    
    //Set data member variables of pointer to head, or the beginning of the list
    pointer = head;
    
    //Establish a circular list and remove the third suitor
    //Used http://www.cplusplus.com/forum/beginner/122056/ as a reference
    while(pointer != pointer->link)
    {
        pointer = pointer->link;
        
        NodePtr former = pointer;
        
        pointer = pointer->link;
        
        NodePtr next = pointer->link;
        
        former->link = next;
        
        cout<<"Removing suitor number: "<<pointer->number<<endl;
        
        delete pointer;
        
        pointer = next;
        
    }
    
    cout<<"The suitor who takes the princess's hand is: "<<pointer->number<<endl;
    
    delete pointer;
    
    return 0;
}
