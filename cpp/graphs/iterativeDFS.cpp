#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;
 
// This class represents a directed graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void DFS(int s);  // prints all vertices in DFS manner
    // from a given source.
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int s){
    stack<int> st;
    vector<bool> visited(V,false);
    
    st.push(s);
    while(!st.empty()){
        int u=st.top();
        st.pop();

        if (visited[u]==false)   
        {
            cout<<u<<" ";
            visited[u]=true;
        }

        for(auto i=adj[u].begin();i!=adj[u].end();i++){
            if(visited[*i]==false){
                st.push(*i);
            }
        }
    }
}

int main()
{
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS(0);
 
    return 0;
}