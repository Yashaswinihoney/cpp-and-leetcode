//DFS based solution for a undirected graph
#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int> >& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool DFSrec(vector<vector<int> > adj, int s, vector<bool>& visited, int parent){
    visited[s]=true;
    for(int u:adj[s]){
        if(visited[u]==false){
            if(DFSrec(adj,u,visited,s)) return true;
        }
        else if(u!=parent) return true;
    }
    return false;
}

bool DFS(vector<vector<int> > adj, int V){
    vector<bool> visited(V,false);

    //for handling the fact that there can be many disconnected 
    //sub graphs inside the graph
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(DFSrec(adj,i,visited,-1)) return true;
        }
    }
    return false;
}

int main(){
    int V=6;
    vector<vector<int> > adj(V);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,4);
    //addEdge(adj,2,4);
    addEdge(adj,4,5);
    addEdge(adj,1,3);
    addEdge(adj,2,3);

    if(DFS(adj,V)){
        cout<<"cycle found"<<endl;
    }
    else{
        cout<<"no cycle found"<<endl;
    }
    return 0;
}