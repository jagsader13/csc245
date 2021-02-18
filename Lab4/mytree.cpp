#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    BinarySearchTree<int> t(0);
    t.insert(6);
    t.insert(2);
    t.insert(8);
    t.insert(1);
    t.insert(4);
    t.insert(3);
    t.printTree();
    cout << endl;
    t.postOrder();
    cout << endl;
    cout << endl;
    cout<< "The height of the tree: " << t.height() << endl;
    cout << endl;
    cout << "The number of leaves: " << t.numLeaves() << endl;
    cout << endl;
   if(t.isBalanced()==true)
   {
       cout << "It's balanced!" << endl;
   }
   else
   {
       cout << "It's not balanced!" << endl;
   }
    t.insert(9);
  if(t.isBalanced()==true)
   {
       cout << "It's balanced!" << endl;
   }
   else
   {
       cout << "It's not balanced!" << endl;
   }
   
}