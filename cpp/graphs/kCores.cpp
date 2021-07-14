#include<iostream>
#include<list>
#include<vector>

using namespace std;
 
// This class represents a undirected graph using adjacency
// list representation
class Graph
{
    int V; // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<int> *adj;
public:
    Graph(int V); // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v);
 
    // A recursive function to print DFS starting from v
    bool DFSUtil(int v, vector<bool> & visited, vector<int> &vDegree, int k);
 
    // prints k-Cores of given graph
    void printKCores(int k);
};

Graph::Graph(int v){
    this->V = v;
    list<int> *adj=new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::DFSUtil(int v, vector<bool>& visited, vector<int> &vDegree, int k){
    visited[v]=true;
    
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(vDegree[*i]<k){
            vDegree[*i]--;
        }

        if(visited[*i]==false){
            DFSUtil(*i,visited,vDegree,k);
        }
    }
}

void Graph::printKCores(int k){
    vector<bool> visited(V,false);
    vector<bool> processed(V,false);

    vector<int> vDegree(V,0);

    for(int i=0;i<V;i++){
        for(auto u:adj[i]){
            vDegree[i]++;
        }
    }

    for(int i=0;i<V;i++){
        if(visited[i]==false){
            DFSUtil(i,visited,vDegree,k);
        }
    }

    cout<<"k cores"<<endl;

    for(int u=0;u<V;u++){
        if(vDegree[u]>=k){
            cout<<endl<<u<<endl;

            for(auto i=adj[u].begin();i!=adj[u].end();i++){
                if(vDegree[*i]>=k){
                    cout<< *i<<" ";
                }
            }
        }
    }
}


