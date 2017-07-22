#include <stdio.h>
#include <limits.h>
# include<iostream>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;

#define V 400
 
int minKey(float key[], bool mstSet[], int vertex)
{
   // Initialize min value
   float min = (float)INT_MAX, min_index;
 
   for (int v = 1; v < vertex+1; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, float graph[V+1][V+1])
{ 
   for (int i = 2; i < n+1; i++)
      cout <<parent[i] << " "<< i<< endl;

}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(float graph[V+1][V+1], int vertex)
{
     int parent[V+1]; 
	 // Array to store constructed MST
     float key[V+1];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V+1];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 1; i < vertex+1; i++)
        key[i] =(float) INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[1] = 0.0;     // Make key 0 so that this vertex is picked as first vertex
     parent[1] = -1;
	  // First node is always root of MST
 
     // The MST will have V vertices
     for (int count = 1; count < vertex; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet, vertex);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 1; v < vertex+1; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     // print the constructed MST
     printMST(parent, vertex, graph);
}
 
 
// driver program to test above function
int main()
{     int T, vertex;
   
      cin >> T;
   while(T--){
   	    cin >> vertex;
	   float graph[V+1][V+1];
	    int X[vertex+1], Y[vertex+1];
       for(int i=1;i<vertex+1; i++)
            cin >> X[i]>> Y[i];
            
        for(int i=1;i<vertex+1; i++)
	     for(int j=1;j<vertex+1; j++)
	       { if(i==j) graph[i][j]=0.0;
		     else
		    graph[i][j]=sqrt(pow((X[i]-X[j]),2)+pow((Y[i]-Y[j]),2));
	          }     
   	 primMST(graph,vertex);
   }
    
 
    return 0;
}