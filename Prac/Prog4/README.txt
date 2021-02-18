Project Goal: This project is to show how Dijkstra's Algorithm works using various input files from the project folder. The project 
should keep track of the starting cities, the destination, and the trip length which is input in a file within the project folder. The
user should be able to input the starting destination or vertex, and using that starting vertex, a table can be constructed where it 
gives the distance traveled and the previous location. 
 
Specifications: The project uses input from the command line that is given by the user. Within the project directory, there are four 
sample files that can be used to test Dijkstra's Algorithm. The files--ginfile1.dat, ginfile2.dat, ginfile3.dat, and ginfile4.dat--have
varying data within. Some of the files hold city names with distances for how long it takes to get to the respective city. Others 
contain numbers as the starting vertex and the destination. ginfile2.dat contains neither city or number for the starting vertices or 
the final destination. It contains the letter v with a respective number after the v such that the values range from v1 to v9. 

Once the data has been read in from the file, it is to be stored within its proper variable within the client file. From there, the 
Dijkstra's Algorithm can be used to build a table. The table that is output will print the starting vertex, the distance traveled, and
the location that it started from. For example, the starting vertex could be Washington which means that its distance would be 0, and
the previous destination would be N/A since we are starting at Washington. The other cities within the file will follow after 
Washington, and their distances will be determined using the algorithm. Their previous cities will also be determined and displayed in
the table.

Algorithm: The client file is made up of 10 different methods: insertionSort, checkInFile, buildDGraph, printCities, setStart, printRow,
findMin, dijkstra, allMarked, and assignWeights. Each method has a specific purpose. The insertionSort method orders the cities or 
vertices in alphabetical order. checkInFile makes sure that the user input a file on the command line, and if a file is not found, the 
program will let the user know before terminating. The buildDGraph is used by taking the input from the file and separating the data 
within using getline and delimiters. printCities will print the cities or the vertices that are within the file. The setStart method
will ask for the user to specify where they want the program to start meaning that if there were five cities and they wanted to start at
Denver, they would input Denver, and the graph would form based on their input. If the city is not found, the user would be informed and
allowed to try again. The printRow method prints the data into a table based on what type of variable it is. findMin finds the minimum
unmarked values within the table. dijkstra's method performs the algorithm. allMarked checks to see if all vertices have been marked. 
assignWeights assigns weight values based on the starting location. It helps determine the shortest path. 

Graph Class: The graph class will be implemented through the client file for this project. It is used when building the table of the 
Dijkstra's Algorithm, and it used in the assignWeights method as well as the dijkstra's method. The graph class uses queues to allow
pass by reference of values. Since the purpose of Dijkstra's Algorithm is to show the shortest path, one must know all of the paths that are available to the one location. By the graph class using queues, all of the nodes that a specific vertex is connected to is shown.
The graph class also uses methods that make building Dijkstra's Alorithm easier. It contains AddVertex, AddEdge, GetToVertices, and 
WeightIs. These methods help build the graph easier by adding the vertex or edge to a queue that is later used to help chart the best
path to travel.  

Sample Input: The sample input will come from ginfile2.dat, and the file's contents can be found below.

ginfile2.dat

V1;V2;2
V2;V5;10
V1;V4;1
V3;V1;4
V3;V6;5
V5;V7;6
V2;V4;3
V4;V6;8
V4;V3;2
V4;V5;2
V4;V7;4
V7;V6;1

Sample Output: The sample output

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	DIJKSTRA'S ALGORITHM	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

			A Weighted Graph Has Been Built for These 8 Cities:
		
				V1		V2		V3
				V4		V5		V6
				V7

			Please input your starting vertex: V1
--------------------------------------------------------------------------------------------------
			Vertex		Distance	Previous

			V1		0		N/A
			V2		2		V1
			V3		3		V4
			V4		1		V1
			V5		3		V4
			V6		8		V3
			V7		5		V4
--------------------------------------------------------------------------------------------------
Dijkstra's Algorithm is about finding the shortest path possible for a set of data. In the file that was used, there were seven differentinputs, and not all of them were used as a vertex. Some were just used as a destination value. When one goes about implementing
Dijkstra's Algorithm, it helps to draw a diagram with the vertices and then connecting them to their corresponding vertex. For example,
V1 is connected to V4 with a distance of 1, so in a diagram that was drawn, V1 would be connected to V4 with an arrow that has a 
distance of 1 written on it. 

After building the diagram, a table can be created using the column titles above. In the table that I crafted, I also had a column 
called mark. Each vertext originally starts as F in the mark column, and they become true as we traverse the table. The table of
Dijkstra's Algorithm is traversed by using the graph that is built. 

After determining the starting vertex, and in this case it was V1, you enter the distance for adjacent vertices. For V1, the adjacent
vertices were V2 and V4, so in the previous column next to V2 and V4, V1 would be placed. In the distance column, the values that
correspond to the distance traveled from V1 to V2 or V1 to V4 would be inserted. For V1 to travel to V2, the distance would be 2, and 
to travel to V4 from V1, the distance would be 1. 

Note that Dijkstra's Algorithm is a type of greedy algorithm that is similar to the Huffman encoding algorithm. The Huffman encoding
used the two smallest values while the Dijkstra's Algorithm looks for the smallest, non-marked vertex. That vertex becomes T sub 1 in themark column, and then it is used to determine the distances for adjacent vertices. However, this time time the distance will be slightly
different since this vertex is not the starting value. The distance will now include prior distances. You will continue this until all
vertices are marked, and if any smaller distances are found then you replace the distance with the smaller total distance found. 
