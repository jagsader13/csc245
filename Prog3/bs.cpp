//Colton Steinbeck//
//Zip File using Maps//
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdio.h>
#include <fstream>
#include <string>
#include "huffman.h"
#include <map>
using namespace std;
void OpenTheFile(ifstream& file, int argChar, char* argVector[]);
void FillInMap(map<string, char>& map, ifstream& file, string info, string comp, char* argVector[]);
int main(int argChar, char* argVector[])
{
	ifstream file;
	string code;
	string comp;
	map<string, char> map;
	OpenTheFile(file, argChar, argVector);
	FillInMap(map, file,  code, comp, argVector);
	printf("File Successfully Inflated Back to Original Size.");
	return 0;
}
//Opens the file entered after the executable file has been called (a.out)//
void OpenTheFile(ifstream& file, int argChar, char* argVector[])
{
	if (argChar == 1) //Loop to find the file
	{
		cout << "File has not been entered." << endl;
		exit(1);
	}
	string filename = argVector[1]; //
	file.open(filename.c_str());
	string unzip = filename.substr(filename.find("."), 3); //String that pulls info from the file to be unzipped//

	if (unzip.compare("zip") == 0)
	{
		cout << "The file was not able to zip. Try again" << endl;
		exit(1);
	}
}
//Fills the map and returns it to file form//
void FillInMap(map<string, char>& map, ifstream& file, string info, string comp, char* argVector[])
{
	int header, ascii;
	file >> header;
	for (int i = 0; i < header; i++)
	{
		file >> ascii >> info; 
		map[info] = (char)ascii;
	}
	//Retrieves the line of code
	file >> comp;
	file.close();
	ofstream outputFile;
	string fileName = argVector[1];
	fileName = fileName.substr(0, fileName.find(".")); //Pulls all info in the file//
	outputFile.open(fileName.c_str());
	string check;
	int pos = 0;
	int val = 1;
	//Loop that traverses the binary code for unzipping//
	for (int i = 0; i < comp.length(); i++)
	{
		check = comp.substr(pos, val);
		if (!(map.find(check) == map.end()))
		{
			outputFile << map.at(check);
			pos = i + 1;
			val = 1;
		}
		else
			val++;
	}
	outputFile.close();
}

