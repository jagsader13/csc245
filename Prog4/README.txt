Jacoby Barry
Dr. Digh
CSC 245
9 December 2020
                    Project 4 README

    Problem Description

The purpose of this assignment is to have students implement a client file using the operations of the Graph class 
to produce a summary table of the shortest paths from a vertex using Dijkstra’s Algorithm, and check for any cycles 
that may exist in the graph.

    Specifications

Build a directed graph of vertices from the data stored in a given input file, print out a listing of vertices 
contained in the graph in sorted order (three per line), and produce a summary table of the shortest paths from a 
starting vertex input by the user to all other vertices.

    Client Algorithm

We use Dijkstra’s Algorithm to build the summary table of given vertices. 
Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph.
After my graph of strings, my array of structs, and my array of strings were built, 
I initialized a queue to hold the adjacent vertices when using the GetToVertices method in the Graph class. 
After getting the starting vertex from the user, I mark it as visited, set its distance to 0, 
and printed out the data corresponding to this index using my printRow method with “N/A” used as the previous vertex.
Then I started a while loop until my boolean function that tells me if all vertices has been marked returns true.
Next, I determined the vertex which is next to my current vertex using the GetToVertices method.
If the next vertex is unmarked and its distance value is greater than the weight 
value and the distance of the last marked vertex (your current vertex) put together, 
then I set its distance value to that total distance and put the name of the current vertex as the previous 
vertex of each adjacent vertex. This process goes until the queue is empty and then I calculate the minimum distance 
next iterating through my array of structs using a for loop. Once I find the minimum distance out of all the unmarked 
vertices, I set this vertex as my new current vertex and mark it. After this I finally print out the row for my current vertex 
and then I repeat the while over unitl all vertices are marked. To go through my vertices throughout this algorithm, I used the
indexes to navigate my array of structs. 

    Sample Input 

Atlanta;Augusta;140
Augusta;Atlanta;140
Atlanta;Athens;70
Athens;Atlanta;70
Atlanta;Macon;80
Macon;Atlanta;80
Macon;Savannah;160
Savannah;Macon;160
Macon;Valdosta;150
Valdosta;Macon;150
Macon;Warner Robins;20
Warner Robins;Macon;20
Savannah;Baxley;110
Baxley;Savannah;110
Macon;Baxley;120
Baxley;Macon;120
Ft. Oglethorpe;Atlanta;110
Atlanta;Ft. Oglethorpe;110
Norcross;Atlanta;20
Atlanta;Norcross;20
Suwanee;Norcross;20
Norcross;Suwanee;20
Suwanee;Atlanta;30
Atlanta;Suwanee;30
Macon;Conyers;90
Conyers;Macon;90
Conyers;Atlanta;20
Atlanta;Conyers;20
Macon;Athens;90
Athens;Macon;90
Augusta;Athens;90
Athens;Augusta;90
Augusta;Savannah;140
Savannah;Augusta;140

    Sample Output 

^^^^^^^^^^^^^^^^        DIJKSTRA'S ALGORITHM    ^^^^^^^^^^^^^^^^ 
 
 A Weighted Graph Has Been Built For These 12 Vertices: 

            Athens           Atlanta           Augusta
            Baxley           Conyers    Ft. Oglethorpe
             Macon          Norcross          Savannah
           Suwanee          Valdosta     Warner Robins
                  

Please input your starting vertex: Conyers
-----------------------------------------------------------------------
        Vertex          Distance        Previous
       Conyers                 0             N/A
       Atlanta                20         Conyers
      Norcross                40         Atlanta
       Suwanee                50         Atlanta
         Macon                90         Conyers
        Athens                90         Atlanta
 Warner Robins               110           Macon
Ft. Oglethorpe               130         Atlanta
       Augusta               160         Atlanta
        Baxley               210           Macon
      Valdosta               240           Macon
      Savannah               250           Macon