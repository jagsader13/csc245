#include "queue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
#include <cstdlib>
#include <sstream>
#include <vector>
#include <climits>
#include <iomanip>
#include <stack>
#include <set>

using namespace std;

#include "HashTable.h"


struct VertexType
{
	string name;
	bool marked;
	int distance;
	string previous;	
};

void insertionSort(string cities[], int numVertices);
void checkInFile(int argc);
void buildDGraph(Graph<string> &dGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType myVertices[]);
void printCities(string cities[], int numVertices);
string setStart(string start, int numVertices, VertexType myVertices[]);
void printRow(int location, VertexType myVertices[]);
int findMin(VertexType myVertices[], int numVertices);
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[]);
bool allMarked(int numVertices, VertexType myVertices[]);
int getCity(string start, VertexType myVertices[], int numVertices);
void assignWeights(Graph<string> &dGraph, int numVertices, VertexType myVertices[], int startingLocation, Queue<string>& getTo);
int main(int argc, char* argv[])
{
	checkInFile(argc);	// Checks to see if Filename is given

	// Creation of Input File:
	string filename = argv[1];

	Graph<string> dGraph; 
	int numVertices;
	int numEdges;
	VertexType myVertices [50];
	string cities [50];
	buildDGraph(dGraph, filename, cities, numVertices, numEdges, myVertices);	// Builds the Graph using the data from the external file.
	printCities(cities, numVertices);	// Prints Cities found in file
	dijkstra(dGraph, numVertices, myVertices);	// Computes Dijkstra's Algorithm:
}

// Checks to see if Filename is given:
void checkInFile(int argc)
{
	if(argc == 1){
		cout << "File not entered. Program will now close." << endl;
		exit(1);
	}
}

// Computes Dijkstra's Algorithm:
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[])
{
	/*string start*/; Queue<string> getTo; int index = 0;/* int startingLocation, index = 0*/;
	string start;
	start = setStart(start, numVertices, myVertices);

	VertexType vertStart = myVertices[getCity(start, myVertices, numVertices)];

	vertStart.distance = 0;
	vertStart.previous = "N/A";
	vertStart.marked = true;
	int startingLocation = getCity(start, myVertices, numVertices);
	//myVertices[numVertices].distance = 0;
	assignWeights(dGraph, numVertices, myVertices, startingLocation, getTo);
	//getCity(cities, start, numVertices);

	VertexType current = vertStart;	
	while(!(allMarked(numVertices, myVertices))){
		current.marked = true;
		dGraph.GetToVertices(myVertices[numVertices].name, getTo);
		while(!(getTo.isEmpty())){
			string name = getTo.getFront();
			index = getCity(name, myVertices, numVertices);
			
			VertexType newVertex = myVertices[index];
			if(newVertex.marked == false){
				int totalDistance = current.distance + dGraph.WeightIs(current.name, newVertex.name);
				//cout <<"This is the total distance " << totalDistance << endl;
				if(totalDistance < newVertex.distance){
					newVertex.distance = totalDistance;
					newVertex.previous = current.name;
					//myVertices[numVertices].previous = current.name;
					myVertices[getCity(newVertex.name, myVertices, numVertices)];
				}
			}
			getTo.dequeue();
			myVertices[getCity(current.name, myVertices, numVertices)];
		}
	}
			//myVertices[getCity(current.name, myVertices, numVertices)];
			//numVertices++;	
		/*index = findMin(myVertices, numVertices);
		cout <<"This is the index outside of the while loop " << index << endl;
		if(index != -1){
			start = myVertices[index].name;
			cout <<"This is the start inside of if index not negative one" << start << endl;
		}
		else
			break;
		myVertices[index].marked = true;
	}
	int cityOrder = 0;
	bool isMarked[numVertices];

	for(int i = 0; i < numVertices; i++)
		isMarked[i] = false;
	cout << endl;

	while(cityOrder < numVertices){
		int dist = INT_MAX;
		int min = 0;
		for(int i = 0; i < numVertices; i++){
			if((myVertices[i].distance < dist) && (isMarked[i] == false)){
				min = i;
				cout <<"The minimum value: " << min << endl;
				dist = myVertices[i].distance;
				cout <<"The distance value: " << dist << endl;
			}
		}
		printRow(min, myVertices);
		isMarked[min] = true;
		cityOrder++;
	}
*/
	VertexType min;
	min.distance = INT_MAX;
	for(int i = 0; i < numVertices; i++){
		VertexType dist = myVertices[i];
		if(dist.distance <= min.distance && !dist.marked){
			min = dist;
		}
	}
	current = min;

	printRow(numVertices, myVertices);			

}	
// Assign weights based on the starting location
void assignWeights(Graph<string> &dGraph, int numVertices, VertexType myVertices[], int startingLocation, Queue<string>& getTo)
{
	string start; int currVer, prevVert, totalWeight;
	//getCity(myVertices, start, numVertices);
	//setStart(start, numVertices, myVertices);
	dGraph.GetToVertices(myVertices[startingLocation].name, getTo);
	
	while(!getTo.isEmpty()){
		string cityName = getTo.dequeue();
		currVer = getCity(start, myVertices, numVertices);
		totalWeight = dGraph.WeightIs(myVertices[startingLocation].name, myVertices[currVer].name);
		
		if(myVertices[currVer].distance != 0){
			int tempC = myVertices[currVer].distance;
			cout << tempC << endl;
			myVertices[currVer].distance = tempC + totalWeight;
		}
		else
			myVertices[currVer].distance = totalWeight;
				
	}	 	
}

// Checks to see if all Vertices have been marked:
bool allMarked(int numVertices, VertexType myVertices[])
{
	for(int i = 0; i < numVertices; i++){
		if(myVertices[i].marked == true)
			return true;
		else
			return false;
	}
			
}

//Determines the index value of a given string is within array of strings
int getCity(string start, VertexType myVertices[], int numVertices)
{
	/*int i = 0, index = 0;
	while(myVertices[i].name.compare(start) != 0){
		i++;
	} 
	index = i;
	return i;	*/
	
	int i = 0;
	for(i; i < numVertices; i++)
		if(myVertices[i].name == start)
			break;
		return i;

}
// Builds the Graph using the data from the External File:
void buildDGraph(Graph<string> &dGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType myVertices[])
{
	const string NotFound = "ZZZ";
	ifstream infile;
	infile.open(filename.c_str());
	string city1, city2, line, newcity1, newcity2; numVertices = 0; int weight;
	VertexType vert1, vert2;
	HashTable<string> Cities(NotFound, 50); //helps prevent duplicates for the cities
	
	if(infile.is_open()){
		while(infile.peek() != EOF){
			getline(infile, city1, ';');
			if((Cities.find(city1) != city1)){
				dGraph.AddVertex(city1); 
				Cities.insert(city1);
				cities[numVertices] = city1;
				newcity1 = cities[numVertices];
				vert1.name = newcity1;
				vert1.distance = INT_MAX; 
				vert1.marked = false;
				myVertices[numVertices] = vert1;
				numVertices++;
			}
			getline(infile, city2, ';');
			if((Cities.find(city2) != city2)){
				dGraph.AddVertex(city2); 
				Cities.insert(city2);
				cities[numVertices] = city2;
				newcity2 = cities[numVertices];
				vert2.name = newcity2;
				vert2.distance = INT_MAX;
				vert2.marked = false;
				myVertices[numVertices] = vert2;
				numVertices++;
			}
			getline(infile, line);
			weight = atoi(line.c_str());
			dGraph.AddEdge(city1, city2, weight);
			numEdges++;
			
		}
	}				
}

// Prints Cities found in External File:
void printCities(string cities[], int numVertices)
{
	cout <<"^^^^^^^^^^^^^^^^	DIJKSTRA'S ALGORITHM	^^^^^^^^^^^^^^^^ " << endl;
	cout <<" \n A Weighted Graph Has Been Built For These " << numVertices <<" Cities: " << endl;	
	insertionSort(cities, numVertices);
	for(int i = 0; i <= numVertices; i++){
			cout << setw(18) <<  cities[i];
		}
		cout << '\n';
		
}

// Sorts the Cities Alphabetically:
void insertionSort(string cities[], int numVertices)
{
	string temp = cities[0];
	
	for(int i = 1; i < numVertices; i++)
	{
		temp = cities[i];
		int j = 0;
		for(j = i; j > 0; j--)
			if(temp < cities[j-1])
				cities[j] = cities[j-1];
			else break;
		cities[j] = temp;
	}
		
}

//Sets the Starting Value in Dijsktra's Algorithm:
string setStart(string start, int numVertices, VertexType myVertices[])
{
	cout << " Please input your starting vertex: ";
	string response;
	getline(cin,response);
	bool isThere = false;
	for (int i = 0;	i < numVertices; i++)
	{
		if (myVertices[i].name.compare(response) == 0)
		{
			start = response;
			return start;
		}
	}
	while (!isThere)
	{
		cout << " Starting location does not exist..." << endl;
		cout << " Please input your new vertex: ";
        	string response;
        	cin >> response;
		for (int i = 0; i < numVertices; i++)
        	{
                	if (myVertices[i].name.compare(response) == 0)
			{
                        	start = response;
                        	return start;
                	}
        	}
	}
}

// Finds the minimum non-marked values in VertexType Array:
int findMin(VertexType myVertices[], int numVertices)
{
 		int minWeight = INT_MAX - 1;
                int minThing = -1;
		for (int i = 0; i < numVertices; i++)
                {
                        if (myVertices[i].distance < minWeight && !myVertices[i].marked)
                        {
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }
			else if (myVertices[i].distance == minWeight && !myVertices[i].marked)
        		{
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }

		}        
		return minThing;
}

// Prints a given row in a Summary Table:
void printRow(int location, VertexType myVertices[])
{
	if (myVertices[location].distance != -1)
	cout << setw(14) << myVertices[location].name << setw(18) << myVertices[location].distance << setw(16) << myVertices[location].previous << endl;
	else
	 cout << setw(14) << myVertices[location].name << setw(18) << "Not On Path" << setw(16) << myVertices[location].previous << endl;
}

