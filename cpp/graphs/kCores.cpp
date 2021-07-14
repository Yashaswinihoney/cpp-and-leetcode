//this is to print the nodes in a graphs that have degree 
//greater tha k for undirected graph
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
    adj=new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::DFSUtil(int v, vector<bool>& visited, vector<int> &vDegree, int k){
    visited[v]=true;
    
    //to update the degrees of v and its adjacents acoordingly
    for(auto i=adj[v].begin();i!=adj[v].end();++i){

        //if degree of v is less than k then we decrease
        //the degrees of its adjacents by 1 
        //since this node is not going to be printed
        if(vDegree[v]<k){
            vDegree[*i]--;
        }

        // processing the unprocessed nodes
        if(visited[*i]==false){

            //if degree of adjacents is less than k then it updates
            //the degrees of v and its adjacents too
            DFSUtil(*i,visited,vDegree,k);
        }
    }
    
    //if degree of v is less than k
    return (vDegree[v]<k);
}

void Graph::printKCores(int k){
    vector<bool> visited(V,false);
    vector<bool> processed(V,false);

    vector<int> vDegree(V);

    int min_deg=100;

    //to start with the node of minimum degree
    int startVertex;

    for(int i=0;i<V;i++){
        //storing the degrees of of nodes
        vDegree[i]=adj[i].size();

        if(vDegree[i]<min_deg){
            min_deg=vDegree[i];
            startVertex=i;
        }
    }

    //dfs from the node of min degree
    DFSUtil(startVertex,visited,vDegree,k);

    //for disconnected nodes
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

int main()
{
    int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(k);
 
    return 0;
}
