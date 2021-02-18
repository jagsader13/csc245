#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;
#include "bet.h"

void BET::makeEmpty()
{
    makeEmpty(root);
}

BET::BET()
{
  root = NULL;
}

// Call to postOrder from public
void BET::postorder( ) const
{
     if( isEmpty( ) )
     {
           cout << "Empty tree" << endl;
     }
    else
    {
         postorder( root );
    }         
}

 // Call to postOrder from private -- Accesses the Root Ptr 

void BET::postorder(BETPtr t) const
{
     if( t != NULL )
     {
          postorder(t->left );
          postorder( t->right );
          cout << t->info.theContent.opsymbol<< '\t';
     }
}
// Call to preOrder from public
void BET::preorder() const
{
     if( isEmpty( ) )
     {
           cout << "Empty tree" << endl;
     }
    else
    {
         preorder( root );
    }         
}

 // Call to preOrder from private -- Accesses the Root Ptr 

void BET::preorder(BETPtr t) const
{
     if( t != NULL )
     {
          cout << t->info.theContent.opsymbol << '\t';
          preorder(t->left );
          preorder( t->right );
     }
}

// Call to inorder from public
void BET::inorder() const
{
     if( isEmpty( ) )
     {
           cout << "Empty tree" << endl;
     }
    else
    {
         inorder( root );
    }         
}

 // Call to inOrder from private -- Accesses the Root Ptr 
void BET::inorder(BETPtr t) const  
{
     if( t != NULL )
     {
          inorder(t->left );
          cout << t->info.theContent.opsymbol << '\t';
          inorder( t->right );
     }
}
//Call to makeEmpty from public 
BET::~BET()
{
    makeEmpty();
    cout << "Deconstructing the List" << endl;
}
//Call to makeEmpty from private
void BET::makeEmpty(BETPtr& t) const
{
     if( t != NULL )
     {
          makeEmpty( t->left );
          makeEmpty( t->right );
          delete t;
     }
            t = NULL;
}
//Call to isEmpty from public
bool BET::isEmpty() const
{
     return root == NULL;
}

void BET::insertPrefixOperator (char token)
{
     BinaryNode* newElement=new BinaryNode;
     newElement-> info.whichType=OPERATOR;
     newElement-> info.theContent.opsymbol=token;
     newElement-> left=s.top(); 
     s.pop();
     newElement-> right=s.top(); 
     s.pop();
     s.push(newElement);
     root=newElement;
}

void BET::insertPostfixOperator (char token)
{
     BinaryNode* newElement=new BinaryNode;
     newElement-> info.whichType=OPERATOR;
     newElement-> info.theContent.opsymbol=token;
     newElement-> right=s.top(); 
     s.pop();
     newElement-> left=s.top(); 
     s.pop();
     s.push(newElement);
     root=newElement;
}


 