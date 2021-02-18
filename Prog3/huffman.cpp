#include "huffman.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) 
{
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;
}

bool HuffmanTree:: inTree(char ch) 
{
    bool found=false;
    for(int i=0;i<nodes.size();i++)
    {
        if(nodes[i].ch==ch)
        {
            found=true; 
        }
    }
    return found;
}

int HuffmanTree:: GetFrequency(char ch) 
{
    if(!inTree(ch))
    {
        cout<< "Character is not in the tree!" << endl;
        return -1;
    }
    else
    {
       return nodes[lookUp(ch)].weight;
    }
    
}

int HuffmanTree:: GetFrequency(int i) 
{
        int frequency;
        for(int j=0;j<nodes.size();j++)
        {
            if(nodes[j].ch==i)
            {
                frequency++;
            }
        }
        return frequency;
    
}

int HuffmanTree:: lookUp(char ch) 
{
    int i = 0;
	while (i < numChars)
	{
		if (nodes[i].ch == ch)
		{
			return i;
		}
		i++;
	}
	return -1;
}

string HuffmanTree:: GetCode(char ch) 
{
	return GetCode(lookUp(ch)); 
}


string HuffmanTree:: GetCode(int i) 
{
	if (nodes[i].parent == -1)
	{
		return ""; 
	}	
	else
	{
		return (GetCode(nodes[i].parent) + (char)(nodes[i].childType + '0'));
	}
		
}

void HuffmanTree:: PrintTable() 
{
    int tcount = 1;
	printf("\t++++ Encoding Table ++++\n\n");
	printf("Index\tChar\tWeight\tParent\tChildType\n");
	for (int i = 0; i < numChars; i++)
	{
		if (nodes[i].ch != ' ' && nodes[i].ch != '\0') 
		{ 
			cout << i << "\t" << nodes[i].ch << "\t" << nodes[i].weight << "\t" << nodes[i].parent << "\t" << nodes[i].childType << endl; 
		}
		else if (nodes[i].ch == '\0' && nodes[i].childType != -1)
		{
			cout << i << "\t" << 'T' << tcount << "\t" << nodes[i].weight << "\t" << nodes[i].parent << "\t" << nodes[i].childType << endl;
			tcount++;
		}
		else 
		{
			cout << i << "\t" << 'T' << tcount << "\t" << nodes[i].weight << "\t" << "0" << "\t" << "-1" << endl; 
		}
	}
}

int HuffmanTree:: numNodes() 
{
    return numChars;
}

void HuffmanTree:: build() 
{
	vector<int> array;
	while(!built)
    {
		int minFreq= lowestFrequency(array);
		array.push_back(minFreq);
		int minFreq2 = lowestFrequency(array);
		array.push_back(minFreq2);
		int mergedFreq=nodes[minFreq].weight + nodes[minFreq2].weight;
		insert('\0', mergedFreq);
		nodes[minFreq].parent = nodes.size()-1;
		nodes[minFreq2].parent = nodes.size()-1;
		nodes[minFreq].childType = 0;
		nodes[minFreq2].childType = 1;
		int counter=0;
		for (int i = 0; i < nodes.size(); i++) 
		{
			if (nodes[i].parent == -1) 
			{ 
				counter++; 
			}
		}
		if (counter == 1) 
		{ 
			built = true; 
		}
	}

		
}

int HuffmanTree::lowestFrequency(vector<int>& array) 
{
	int lowestVal = 10000;
	int index = -1;
	for (int i = 0; i < nodes.size(); i++) 
	{
		if ((nodes[i].weight < lowestVal) && !isInArray(array, i)) 
		{
			lowestVal = nodes[i].weight;
			index = i;
		}
	}
	return index;
}

bool HuffmanTree::isInArray(vector<int> array, int index) 
{
	for (int i = 0; i < array.size(); i++) 
	{
		if (array[i] == index) 
		{ 
			return true; 
		}
	}
	return false;
}
