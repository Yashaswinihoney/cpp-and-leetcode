#include<iostream>
#include<vector>
using namespace std;

//for adding edges for undirected graphs
void addEdge(vector<vector<int>> adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//printing the graph
void printGraph(vector<vector<int>> adj, int v){
    for(int i=0;i<adj[v].size();i++){
        cout<<adj[v][i]<<" ";
    }
}
int main(){
    int v=4;
    vector<vector<int>> adj(v);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,2);
    return 0;
}