#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<vector<int> > adj, int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void BFS(vector<vector<int> > adj, int s, vector<bool> &visited){
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";

        for(int i=0;i<adj[u].size();i++){
            if(visited[i]==false){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}

void BFSdis(vector<vector<int> > adj, int v){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            BFS(adj, i, visited);
        }
    }
}

int main() 
{ 
	int V=7;
	vector<vector<int> > adj(V);
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFSdis(adj,V); 

	return 0; 
} 
