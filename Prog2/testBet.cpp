#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;
#include "bet.h"

//Function to print the menu and take in the user sclearelection
void PrintMenu(char &sel)
{
    cout << "Building Binary Expression Trees" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1) Prefix" << endl;
    cout << "2) Infix" << endl;
    cout << "3) Postfix" << endl;
    cout << endl;
    cout << "Your Expression Type: " ;
    cin >> sel;
    cout << endl;
}   
//Method to check precedence
int precedence(char c) 
{ 
    if(c == '*' || c == '/') 
    {
        return 2; 
    }
    else if(c == '+' || c == '-') 
    {
         return 1; 
    }
    else
    {
        return -1; 
    }
} 
//Method to check if a char is a operator
bool isOperator(char character)
{
    if (character == '+' || character == '-' || character == '*' || character == '/')
    {
        return true;
    }
    else
    {
        return false;
    }     
}

//Method to check if a char is a operand
bool isOperand(char operand)
{
    if(operand=='+' || operand=='-' || operand=='*' || operand=='/' || operand==')' || operand=='(')
    {
        return false;
    }
    else
    {
        return true;
    }
    
}
//Method to check if a char is a open parantheses
bool isOpen(char character)
{
    if(character=='(')
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
//Method to check if a char is a closed parantheses
bool isClosed(char character)
{
    if(character==')')
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Method to convert infix to postfix and prefix
void infix(string infix,char &sel,stack<BETPtr&> tree)
{
    string postfix;
    stack <char> st; 
    for(int i=0;i<infix.length();i++)
    {
        if(isOperand(infix.at(i)))
        {
            postfix+=infix.at(i);
        }
        else if(isOpen(infix.at(i)))
        {
            st.push('(');
        }
        else if(isClosed(infix.at(i)))
        {
             while(!st.empty() && st.top() != '(') 
            { 
                char top= st.top(); 
                st.pop(); 
                postfix+=top;
            } 
            if(isOpen(st.top()))
            { 
                char top= st.top(); 
                st.pop(); 
            } 
        }
        else
        { 
            while(!st.empty() && precedence(infix[i]) <= precedence(st.top())) 
            { 
                char top= st.top(); 
                st.pop(); 
                postfix+=top;
            } 
            st.push(infix[i]); 
        } 
    }
    while(!st.empty()) 
    { 
        char top= st.top(); 
        st.pop(); 
        postfix+=top;
    } 
    
    postfix(postfix,sel,tree);
}

//Method to convert postfix to infix and prefix
void postfix(string postfix, char &sel, stack<BETPtr&> tree)
{
    for (int i=0; i< postfix.length(); i++)
    {
        tree.insertPostfixOperator(postfix.at(i));
    }
    cout <<"Prefix Expression Produced From Tree:" << endl;
    tree.preorder();
    cout  << endl;
    cout <<"Infix Expression Produced From Tree:" << endl;
    tree.inorder();
    cout <<endl;
    cout <<"Postfix Expression Produced From Tree:" << endl;
    tree.postorder();
    cout << endl;
    cout<<"Build Another Tree? (Y/N): " << endl;
    cin >> sel;
    cout <<endl;

}
 //Method to convert prefix to postfix and infix
void prefix(string prefix,char &sel,stack<BETPtr&> tree)
{
     for (int i=0; i< prefix.length(); i++)
    {
        tree.insertPrefixOperator(prefix.at(i));
    }
    cout <<"Prefix Expression Produced From Tree:" << endl;
    tree.preorder();
    cout  << endl;
    cout <<"Infix Expression Produced From Tree:" << endl;
    tree.inorder();
    cout <<endl;
    cout <<"Postfix Expression Produced From Tree:" << endl;
    tree.postorder();
    cout << endl;
    cout<<"Build Another Tree? (Y/N): " << endl;
    cin >> sel;
    cout <<endl;
}
//Main method
int main()
{
   stack<BETPtr&> tree;
   char sel;
   string expression;
   do
    {
        PrintMenu (sel);
        cout << "Your Expression: ";
        getline(cin,expression);
        cout << endl;
        switch (sel)
        {
            case '1' :  prefix(expression,sel,tree);  break;
            case '2' :  infix(expression,sel,tree);  break;
            case '3' :  postfix(expression,sel,tree); break;
            default  :   cout << "\tError.  Try Again." << endl;
        }
    } while (toupper(sel) != 'N');
    cout << "Program Now Deconstructing Tree & Exiting..." << endl;
}