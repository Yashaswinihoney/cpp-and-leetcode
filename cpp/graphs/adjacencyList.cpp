#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//for adding edges for undirected graphs
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//printing the graph
void printGraph(vector<vector<int> > adj, int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        /*
        for(auto x: adj[i]){
            cout<<x<<" ";
        }*/
        cout<<endl;
    }
}


//bfs for a connected undirected graph
void BFS(vector<vector<int> > adj, int v, int s){
    vector<bool> visited(v,false);
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";

        for(int i:adj[u]){
            if(visited[i]==false){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}


//bfs for undirected disconnected graph
void BFSDis(vector<vector<int> > adj, int v){
    vector<bool> visited(v+1,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            BFS(adj,v,i);
        }
    }
}
int main(){
    int v=5;
	vector<vector<int> > adj(v);
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);

    printGraph(adj,4);
    //BFS(adj,v,0);
    return 0;
}