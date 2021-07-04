#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void add(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//dfs for connected undirected graph
//recurrsive function
void DFSrec(vector<vector<int> > adj, vector<bool>& visited, int s){
    visited[s]=true;
    cout<<s<<" ";
    for(auto i:adj[s]){
        if(visited[i]==false){
            DFSrec(adj,visited,i);
        }
    }
}

//dfs wrapper function
void DFS(vector<vector<int> > adj, int v, int s){
    vector<bool> visited(v,false);
    //s here mentioned is like the root in 
    //binary trees, to provide a starting 
    //point for the traversal of a graph 
    DFSrec(adj,visited,s);
}

int main() 
{ 
	int V=5;
	vector<vector<int> > adj(V);
	add(adj,0,1); 
	add(adj,0,2); 
	add(adj,2,3); 
	add(adj,1,3); 
	add(adj,1,4);
	add(adj,3,4);

	cout << "Following is Depth First Traversal: "<< endl; 
	DFS(adj,V,0); 

	return 0; 
} 
