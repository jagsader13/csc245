#include <string>
#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{
    BinaryHeap<char> PQ(50);
    for(char i = 'A'; i < 'K'; i++)
    {
        PQ.insert(i);
    }
    PQ.deleteMin();
    cout <<"Left Subtree of the Root of Heap: ";	
	PQ.printLtSubtree( );
    cout << endl;
    cout << "Height: " << PQ.Height() << endl;
    cout << "Maximum Value: " << PQ.findMax() << endl;
		
}