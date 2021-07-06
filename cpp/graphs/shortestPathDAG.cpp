//to find the shortest path in a directed acyclic graph
#include<iostream>
#include<vector>
#define INF INT_MAX
using namespace std;

// this class defines the node of the graph
class AdjListNode{
    public:
    int v;
    int weight;

    //contructor to intitialise a adj list
    //wieghted node, of the given index and weight
    AdjListNode(int _v, int _w){
        v=_v;
        weight=_w;
    }
    int getV(){
        return v;
    }
    int getWeight(){
        return weight;
    }
};

class Graph{
    public:
    int V;
    vector<AdjListNode> *adj;
    void topologicalSort(int v, vector<bool>& visited, vector<int> st);

    Graph(int v){
        V=v;
        adj=vector<AdjListNode>(V);
    }
    void addEdge(int u, int v, int weight);
    void shortestPath(int s);
};

void Graph::addEdge(int u,int v, int weight){
    AdjListNode node(v,weight);
    adj[u].push_back(node);
}