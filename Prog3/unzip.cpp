#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
using namespace std;

void commandLine(string fileName, int argc, char** argv);

int main(int argc, char** argv)//Main method
{
    
    string fileName=argv[1];
    commandLine(fileName,argc,argv);
    string newFile= fileName.substr(0, (fileName.length()- 4)); //Creating the newFile name 
    ifstream infile;        
    ofstream outfile;
    int headerSize;
    string count;
    infile.open(fileName.c_str()); //Opening the input file
    //remove(fileName.c_str());     
    getline(infile,count);  //Getting the count from the first line for the for loop 
    headerSize=atoi(count.c_str());
    map<string, char> m; //Creating the map
    string s; //Coded value
    string lastLine; // Encoded line from the last line
    for (int i = 1; i <=headerSize; i++) //For Loop to fill up the map 
    {
        int ascii;
        string space= " "; 
        string line;
        getline(infile, line);
        s=line.substr(0, line.find(space));
        ascii=atoi(s.c_str());
        s=line.substr(line.find(space) + 1);
        m[s] = (char) ascii;
    }  

    getline(infile, lastLine); //Getting the last line of code
    s= "";
    outfile.open (newFile.c_str());//Opening the output file
    for(int k = 0; k < lastLine.length(); k++)//Filling the output file up with the characters
    {
				if(m.find(s) == m.end())
                {
					s=s+lastLine[k];
				}
				else
                {
					k--;
					outfile << m[s];
					s= "";
				}
	}
    outfile << endl;
	outfile.close();
	infile.close();
	cout << "File Successfully Inflated Back to Original." << endl;
    return 0;
}

//Opens the file entered after the executable file has been called (a.out)//
void commandLine(string fileName, int argc, char** argv)
{
	if(argc==1)//Checking if no file was input on the command line
    {
        cout << "No filename entered. Please enter a filename. Program Terminated." << endl;
        exit(1);
    }
    else if(fileName.substr(fileName.length() -4) != ".zip")//Checking the fileName for the .zip extension
    {
		cout << "Wrong file extention. Please enter a valid file extension. Terminating program." << endl;
		exit(1);
    }
}