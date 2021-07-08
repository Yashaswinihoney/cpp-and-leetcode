#include<iostream>
#include<vector>
#include<iterator>
#include<stack>
#include<list>
//#define INF 100
using namespace std;

//defining the node of a weighted directed graph
class AdjListNode{
    public:
    int v;
    int weight;
    
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

//defing the graph
class Graph{
    public:
    int V;
    //pointer to the first element of the array
    //of adjacency list
    list<AdjListNode> *adj;
    void topologicalSort(int v, vector<bool>& visited, stack<int>& st);

    Graph(int v);

    void addEdge(int u, int v, int weight);

    void shortestPath(int s);
};

//constructor to create the graph
Graph::Graph(int v) 
{ 
	this->V = v; 
	adj = new list<AdjListNode>[V]; 
}

void Graph::addEdge(int u, int v, int weight){
    AdjListNode node(v,weight);
    adj[u].push_back(node);
}

//here topological sort is performed using dfs
void Graph::topologicalSort(int v, vector<bool>& visited, stack<int>& st){
    visited[v]=true;

    list<AdjListNode>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++){
        AdjListNode node=*i;
        if(visited[node.getV()]==false){
            topologicalSort(node.getV(),visited,st);
        }
    }
    st.push(v);
}

void Graph::shortestPath(int s){
    stack<int> st;
    vector<int> dist(V,100);
    vector<bool> visted(V,false);

    for(int i=0;i<V;i++){
        if(visted[i]==false){
            topologicalSort(i,visted,st);
        }
    }

    //since s is the starting point of referece from
    //which we start counting the distnace
    //we mark distance of s from s as 0
    dist[s]=0;

    while (!st.empty())
    {
        int u=st.top();
        st.pop();
        
        list<AdjListNode>::iterator i;

        if(dist[u]!=100){
            for(i=adj[u].begin();i!=adj[u].end();i++){
                if(dist[i->getV()]>dist[u]+i->getWeight()){
                    dist[i->getV()]=dist[u]+i->getWeight();
                }
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
    
}

int main(){
    Graph g(6);
    g.addEdge(0,1,2);
    g.addEdge(0,4,1);
    g.addEdge(1,2,3);
    g.addEdge(4,2,2);
    g.addEdge(4,5,4);
    g.addEdge(2,3,6);
    g.addEdge(5,3,1);

    int s=0;
    g.shortestPath(s);
    return 0;
}