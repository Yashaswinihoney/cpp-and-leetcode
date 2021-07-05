#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
}

bool DFSrec(vector<vector<int> > adj, int s, vector<bool>&visited, vector<bool>& recStack){
    visited[s]=true;
    recStack[s]=true;
    for(auto u:adj[s]){
        if(visited[u]==false&&DFSrec(adj,u,visited,recStack)==true){
            return true;
        }
        else if(recStack[u]==true){
            return true;
        }
    }
    //since s is popped out of the rec stack 
    recStack[s]=false;
    return false;
}

bool DFS(vector<vector<int> > adj ,int V){
    vector<bool> visited(V,false);
    vector<bool> recSt(V, false);

    //to handle disconnected graphs
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(DFSrec(adj,i,visited,recSt)) return true;
        }
    }
    return false;
}
int main(){
    int V=6;
    vector<vector<int> > adj(V);
    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,3);

    if(DFS(adj,V)){
        cout<<"CYCLE"<<endl;
    }
    else{
        cout<<"NO cycle"<<endl;
    }
    return 0;
}