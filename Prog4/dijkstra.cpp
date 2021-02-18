#include "queue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
#include <cstdlib>
#include <sstream>
#include <array>
#include <vector>
#include <climits>
#include <iomanip>
#include <stack>
#include <set>

using namespace std;

struct VertexType //Defining the vertex struct 
{
	string name;
	bool marked;
	int distance;
	string previous;	
};

int getIndex(string city,string cities[]); // Method to get the vertex index from my array of vertex names used when user inputs the desired vertex
void buildGraph(Graph<string> &myGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType vertices[]); //Method to build the graph and initalize my array of structs
void menu(string cities[], int numVertices); // Method to print out the starting menu displaying the sorted vertices
bool inArray(string cities[], string city, int numVertices); //Boolean returning method that tells you whether a vertex is in the array of strings when user inputs the desired vertex
void dijkstra(Graph<string>& dGraph, int numVertices, VertexType vertices[],string cities[]); //Method that runs Dijkstra's Algorithm on the vertices
bool marked(int numVertices, VertexType vertices[]);//Boolean returning method that tells you whether all vertices are marked or not
void printRow(int location, VertexType vertices[]); //Method to print out a vertex's row for the summary table
int getCityIndex(string city,VertexType vertices[],int numVertices);//Method to get a vertex name index from the array of structs

//Main method

int main(int argc, char** argv)
{
    string fileName=argv[1];
    if(argc==1)//Checking if no file was input on the command line
    {
        cout << "Invalid filename! Goodbye!" << endl;
        exit(0);
    }

    string cities [50];//Array of vertex names only
    Graph<string> myGraph(50);//declaring the graph
    int numVertices=0;
	int numEdges=0;
	VertexType vertices[50];//Array of structs

    buildGraph(myGraph, fileName, cities, numVertices, numEdges, vertices);
    menu(cities,numVertices);
    dijkstra(myGraph, numVertices, vertices,cities);
    
}

//Bodies of the methods below

int getIndex(string city,string cities[],int numVertices)//Method returning the index value a given string within the array of strings
{
    int index;
    for(int i = 0; i < numVertices; i++) 
    {
        if(cities[i]==city)
        {
            index=i;
        }
    }
    return index;
}

void buildGraph(Graph<string> &myGraph, string fileName, string cities[], int &numVertices, int &numEdges, VertexType vertices[])
{
	const string NotFound = "ZZZ";
	ifstream infile;
	infile.open(fileName.c_str());
	string city1, city2, line, newcity1, newcity2; int weight;
	VertexType vert1, vert2; 
	
	if(infile.is_open())
    {
		while(infile.peek() != EOF)
        {
			getline(infile, city1, ';');
			if(inArray(cities,city1,numVertices)==false)
            {
				myGraph.AddVertex(city1); 
				cities[numVertices] = city1;
				newcity1 = cities[numVertices];
				vert1.name = newcity1;
				vert1.distance = INT_MAX; 
				vert1.marked = false;
				vertices[numVertices] = vert1;
				numVertices++;
		    }

			getline(infile, city2, ';');

			if(inArray(cities,city2,numVertices)==false)
            {
				myGraph.AddVertex(city2); 
				cities[numVertices] = city2;
				newcity2 = cities[numVertices];
				vert2.name = newcity2;
				vert2.distance = INT_MAX;
				vert2.marked = false;
				vertices[numVertices] = vert2;
				numVertices++;
			}
			getline(infile, line);
			weight = atoi(line.c_str());
			//cout << weight << endl;
			myGraph.AddEdge(city1, city2, weight);
			//myGraph.AddEdge(city2, city1, weight);
			numEdges++;
			//numEdges++;
		}
	}				
}

void menu(string cities[], int numVertices) // Method to print out the starting menu displaying the sorted vertices
{
    int count=0;
    cout << '\n';
    cout <<"^^^^^^^^^^^^^^^^	DIJKSTRA'S ALGORITHM	^^^^^^^^^^^^^^^^ " << endl;
	cout <<" \n A Weighted Graph Has Been Built For These " << numVertices <<" Vertices: " << endl;	
	cout <<endl;

	string temp = cities[0];
	for (int i = 1; i < numVertices; i++)
	{
		temp = cities[i];
		int j = 0;
		for (j = i; j > 0; j--)
			if (temp < cities[j - 1])
				cities[j] = cities[j - 1];
			else break;
		cities[j] = temp;
	}

	for(int i = 0; i <= numVertices; i++)
    {
		cout << setw(18) <<  cities[i];
        count++;
        if(count==3)
        {
            cout << '\n';
            count=0;
        }

	}
	cout << '\n';
	cout << endl;
}

bool inArray(string cities[], string city, int numVertices) //Boolean returning method that tells you whether a vertex is in the array of strings when user inputs the desired vertex
{
    bool found=false;
    for(int i = 0; i < numVertices; i++) 
    {
        if(cities[i]==city)
        {
            found=true;
        }
    }
    return found;
}

void dijkstra(Graph<string>& myGraph, int numVertices, VertexType vertices[],string cities[]) //Method that runs Dijkstra's Algorithm on the vertices
{
	Queue <string> que;
    int startingIndex = 0;
	int totalDistance=0;
	int adjacentIndex=0;
	int prevIndex=0;
	int minIndex=0;
	int min=0;

    string startingVertex;
    cout<< "Please input your starting vertex: ";
    //cin >> startingVertex;
	getline(cin, startingVertex);
    while(inArray(cities,startingVertex,numVertices)==false)
    {
        cout<< "Vertex unavailable! Please enter another value!" << endl;
        cout<< "Please input your starting vertex: ";
        //cin >> startingVertex;
		getline(cin, startingVertex);
    }   
    cout <<"-----------------------------------------------------------------------" << endl;
	cout << setw(14) << "Vertex" << setw(18) << "Distance" << setw(16) << "Previous" << endl;

    startingIndex= getCityIndex(startingVertex,vertices,numVertices);
	vertices[startingIndex].marked=true;
	vertices[startingIndex].distance=0;
	vertices[startingIndex].previous="N/A";
	printRow(startingIndex, vertices);
	prevIndex=startingIndex;

    while(marked(numVertices, vertices)==false)
	{
		myGraph.GetToVertices(vertices[prevIndex].name, que);
		while(!(que.isEmpty()))
        {
			string name = que.getFront();
			//cout<< "Popped: " << name <<endl;
			adjacentIndex = getCityIndex(name,vertices,numVertices);
			totalDistance=vertices[prevIndex].distance + myGraph.WeightIs(vertices[prevIndex].name, vertices[adjacentIndex].name);
			if(vertices[adjacentIndex].marked==false && totalDistance<vertices[adjacentIndex].distance)
            {
					vertices[adjacentIndex].distance = totalDistance;
					vertices[adjacentIndex].previous = vertices[prevIndex].name;
			}
			que.dequeue();
		}

		min = INT_MAX;
		for(int i = 0; i < numVertices; i++)
		{
			VertexType dist = vertices[i];
			if(dist.distance <= min && !dist.marked)
			{
				min=dist.distance;
				minIndex=i;
			}	
		}
		prevIndex=minIndex;
		vertices[prevIndex].marked=true;
		printRow(prevIndex, vertices);
	}
	
}

bool marked(int numVertices, VertexType vertices[]) //Boolean returning method that tells you whether all vertices are marked or not
{
    bool allmarked=true;
    for(int i = 0; i < numVertices; i++)
    {
		if(vertices[i].marked == false)
        {
            allmarked=false;
        }		
	}		
    return allmarked;
}



void printRow(int location, VertexType vertices[]) //Method to print out a vertex's row for the summary table
{
	
	if (vertices[location].distance != 2147483647  && vertices[location].distance >= 0)
	{
		cout << setw(14) << vertices[location].name << setw(18) << vertices[location].distance << setw(16) << vertices[location].previous << endl;
	}
	else
	{
		cout << setw(14) << vertices[location].name << setw(18) << "Not On Path" << setw(16) << "N/A" << endl;
	}
}

int getCityIndex(string city,VertexType vertices[],int numVertices)//Method returning the index value a given string within the array of strings
{
    int index;
    for(int i = 0; i < numVertices; i++) 
    {
        if(vertices[i].name==city)
        {
            index=i;
        }
    }
    return index;
}


