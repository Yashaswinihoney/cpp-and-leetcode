//to find the number of connected components
//in a undirected graph
#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(vector<vector<int> > adj, vector<bool>& visited, int s){
    visited[s] = true;
    cout<<s<<" ";
    for(int i:adj[s]){
        if(visited[i]==false){
            dfs(adj, visited,i);
        }
    }
}
void printGraph(vector<vector<int> > adj, int v){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfs(adj,visited,i);
            cout<<endl;
        }
    }
}
int main(){
    int v=5;
    vector<vector<int> > adj(v);
    addEdge(adj,1,0);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    printGraph(adj,v);
    return 0;
}