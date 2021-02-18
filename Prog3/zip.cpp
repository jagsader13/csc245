#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include "huffman.h"
#include <stdlib.h>
#include <cctype>
using namespace std;

int main(int argc, char** argv)//Main method
{
    bool tableEnabled=false;//Bool to check if the table is supposed to be printed
    string fileName=argv[1];
    string dashT=argv[1];
    string dashH=argv[1];
    const int NumLetters = 256;
    int Letters[NumLetters];
    int header=0;//Holds the top number in the zip file 
    int numChars=0;
    int characters=0;
    char ch;
    HuffmanTree T;
    string s;
    int compressed = 0;
	float compressratio;

    if(dashT=="--t")//Checking for user input for table 
  	{
   	fileName = argv[2];
		tableEnabled = true;
    }

    else if(dashH =="--help")//Checking for user input for help options
    {
        string printHelp;
        ifstream help;
        help.open("help");
        while(getline(help, printHelp))
        {
          cout << printHelp << endl;
        }
        help.close();
		    return 0;
  	}

    else
    {
      if(argc==1)//Checking if no file was input on the command line
      {
          cout << "No filename entered. Please enter a filename. Program Terminated." << endl;
          exit(0);
      }
    }

    ifstream infile;        
    ofstream outfile;
    string line;
    
    infile.open(fileName.c_str()); //Opening the input file

    for (char ch = char(0);  ch <= char(126);  ch++)//Getting the characters from the input file 
	  {
		  Letters[ch] = 0;
	  }
    infile.get(ch);
	  while (infile)
	  {
      Letters[ch] += 1;
      s+=ch;
      infile.get(ch);
	  }

  for (char ch = char(0); ch <= char(126); ch++)//Building the tree
		if ((Letters[ch] != 0) && (ch != '\n') && (ch != ' '))
		{
			T.insert(ch, Letters[ch]);
			header++;
		}
		else if ((Letters[ch] != 0) && (ch == '\n'))
		{
			T.insert('^', Letters[ch]);
			header++;
		}
		else if ((Letters[ch] != 0) && (ch == ' '))
		{
      T.insert('$', Letters[ch]);
			header++;
		}
      
    
    
    T.build();//Sorting the tree 
	if(tableEnabled)//Checking to see if the table needs to be printed
    {
    		T.PrintTable();		
    }
   	infile.close();
	remove(fileName.c_str());
    string zipFileName=fileName+".zip";//Makes the zip file name
    outfile.open(zipFileName.c_str());
    outfile << header << endl; //Puts the header in the zip file 
    int inputNum;
    for (char ch = char(0); ch <= char(126); ch++)//Prints out the zip file info
		{
			if ((Letters[ch] != 0) && (ch != '\n') && (ch != ' '))
			{
				outfile << (int)ch << " " << T.GetCode(ch) << endl;
				inputNum++;
			}
			else if ((Letters[ch] != 0) && (ch == '\n'))
			{
				outfile << (int)ch << " " << T.GetCode('^') << endl;
				inputNum++;
			}
			else if ((Letters[ch] != 0) && (ch == ' '))
			{
				outfile << (int)ch << " " << T.GetCode('$') << endl;
				inputNum++;
			}
		}
    	char code;
		for (int i = 0; i < s.length(); i++)//Prints out the encoded string
		{
			code = s[i];
			outfile << T.GetCode(code);
			compressed++;
		}
		outfile << endl;
		outfile.close();
		compressratio = (1 - (float)(compressed / ((float)inputNum * 8))) * 100;//Prints out the compression info
		cout << "File Successfully Compressed to " << compressed << " Bits (" << compressratio << "% Less)" << endl;
  	
   
   return 0;
}