#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<vector<int> > adj, int v, int s, vector<int> &dist){
    vector<bool> visited(v,false);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int v:adj[curr]){
            if(visited[v]==false){
                //since v is the adjacent of curr 
                //the distance will be incremented by 1
        
                dist[v]=dist[curr]+1;
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main(){
    int V=4;
    vector<vector<int> > adj(V);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    vector<int> dist(V,INT32_MAX);
    dist[0]=0;
    BFS(adj,V,0,dist);
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}