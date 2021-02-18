#include <cstddef> 
#include <iostream>

using namespace std;
#include "dlist.h"

void PrintMenu(char &selection)//Function to print the menu and take in the user selection
{
    cout << "Menu" << endl;
    cout << "H: Insert item at front" << endl;
    cout << "T: Insert item at back" << endl;
    cout << "A: Access an item in list" << endl;
    cout << "D: Delete an item in list" << endl;
    cout << "P: Print the list" << endl;
    cout << "L: Print the list's length" << endl;
    cout << "Q: Quit the program" << endl;
    cout << "----------------------------------" << endl;
    cout << "Please enter your choice" << endl;
    cin >> selection;
}   

void destroy(DList<int>& list)//Function to delete any node
{
     if(list.isEmpty()==true)
    {
        cout<< "List is empty! Add a number to the list!" << endl;
         cout << endl;
    }
    else
    {
        cout << "What existing number do you want to delete?" << endl;
        int num;
        cin >> num;
        if(list.inList(num)==true)
        {
            list.deleteItem(num);
             cout << endl;
    }
        else
        {
            cout << "Number is not in list! Try again!" << endl;
             cout << endl;
        }
    }
    
    
}

void insertFront(DList<int>& list)//Function to put a new node at the beginning of the list
{
    int num;
    cout << "What number do you want to add to the front of the list?" << endl;
    cin >> num;
    if(list.inList(num)==false)
    {
        list.insertHead(num);
         cout << endl;
    }
    else
    {
       cout << "Number is already added to list! Try again!" << endl;
        cout << endl;
    }
    
}

void printOut(const DList<int>& list)//Function to print out the whole list
{
    if(list.isEmpty()==true)
    {
        cout<< "List is empty! Add a number to the list!" << endl;
         cout << endl;
    }
    else
    {
        list.print();
         cout << endl;
    }
}

void numItems(const DList<int>& list)//Function to print out the length of the list
{
    if(list.isEmpty()==true)
    {
        cout<< "List is empty! Add a number to the list!" << endl;
         cout << endl;
    }
    else
    {
        cout << "The list has " << list.lengthIs() << " number/numbers on it." << endl;
         cout << endl;
    }
    
    
}

void insertBack(DList<int>& list)//Function to put a new node at the back of the list
{
    int num;
    cout << "What number do you want to add to the back of the list?" << endl;
    cin >> num;
    if(list.inList(num)==false)
   {
        if(list.isEmpty()==true)
        {
            list.insertHead(num);
             cout << endl;
        }
        else
        {
            list.appendTail(num);
             cout << endl;
        } 
    }
    else
    {
         cout << "Number is already added to list! Try again!" << endl;
    }
}

void access(DList<int>& list)//Function to move an existing item to the front of the list 
{
    if(list.isEmpty()==true)
    {
        cout<< "List is empty! Add a number to the list!" << endl;
    }
    else
    {
        int num;
        cout << "What existing number would you like to move to the front?" << endl;
        cin >> num;
        if(list.inList(num)==true)
        {
            list.deleteItem(num);
            list.insertHead(num);
            cout << endl;
        }
        else
        {
             cout << "Number is not in list! Try again!" << endl;
        }
    }
    
}
int main()
{
   DList<int> list;
   char sel;
   do
    {
        PrintMenu (sel);
        switch (toupper(sel))
        {
            case 'H' :   insertFront(list);  break;
            case 'T' :   insertBack(list);  break;
            case 'A' :   access(list);  break;
            case 'D' :   destroy(list);  break;
            case 'P' :   printOut(list); break;
            case 'L' :   numItems(list); break;
            case 'Q' :   cout << "\tExiting Program...\n"; break;
            default  :   cout << "\tError.  Try Again." << endl;
        }
    } while (toupper(sel) != 'Q');
    
}