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

void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent){
    visited[u]=true;
    static int t=0;

    disc[u]=low[u]=++t;

    for(auto i=adj[u].begin();i!=adj[u].begin();i++){
        int v=*i;

        if(visited[v]==false){
            parent[v]=u;
            bridgeUtil(v,visited,disc,low,parent);

            low[u]=min(low[u],low[v]);

            if(low[v]>disc[u]){
                cout<<u<<" "<<v<<endl;
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}

void Graph::bridge(){
    vector<bool> visited(V,false);
    vector<int> disc(V);
    vector<int>low(V);
    vector<int> parent(V);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            bridgeUtil(i,visited,disc,low,parent);
        }
    }
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
