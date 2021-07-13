#include<iostream> 
#include <list> 
#include <vector>
#define NIL -1
using namespace std; 

class Graph 
{ 
	int V; 
	list<int> *adj; 
	void APUtil(int v, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap); 
public: 
	Graph(int V);  
	void addEdge(int v, int w); 
	void AP(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); 
} 

static int t=0;
void Graph::APUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>&parent, vector<bool>& ap){
    visited[u]=true;
    int children=0;
    disc[u]=low[u]=++t;

    for(auto i=adj[u].begin();i!=adj[u].end();i++){
        int v=*i;
        if(visited[v]==false){
            children++;
            parent[v]=u;
            APUtil(v,visited,disc,low,parent,ap);

            low[u]=min(low[u],low[u]);
            if(parent[u]==-1&&children){
                ap[u]=true;
            }
            if(parent[u]!=-1&&low[u]>=disc[u]){
                ap[u]=true;
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}
void Graph::AP(){
    vector<bool> visited(V,false);
    vector<bool> ap(V,false);
    vector<int> parent(V,-1);
    vector<int> disc(V);
    vector<int> low(V);

    for(int i=0;i<V;i++){
        if(visited[i]==false){
            APUtil(i,visited,disc,low,parent,ap);
        }
    }
    for(int i=0;i<V;i++){
        if (ap[i]==true)
        {
            cout<<i<<" ";
        }
    }
}

int main() 
{  
	cout << "Articulation points in first graph \n";
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	g.AP(); 
	
	return 0; 
} 

