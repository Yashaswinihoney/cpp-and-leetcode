#include<iostream> 
#include <list> 
#include <vector>
#define NIL -1 
using namespace std; 

class Graph 
{ 
	int V; // No. of vertices 
	list<int> *adj; // A dynamic array of adjacency lists 
	void bridgeUtil(int v, vector<bool>& visited, vector<int>& disc, vector<int>& low, 
					vector<int>& parent); 
public: 
	Graph(int V); // Constructor 
	void addEdge(int v, int w); // to add an edge to graph 
	void bridge(); // prints all bridges 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); // Note: the graph is undirected 
}

void Graph::bridge(){
    
}

int main() 
{ 
	cout << "Bridges in first graph \n"; 
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	g.bridge(); 

	return 0; 
} 
