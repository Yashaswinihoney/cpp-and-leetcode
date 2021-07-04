
/*#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSrec(vector<vector<int> > adj, vector<bool>& visited, int s){
    visited[s]==true;
    cout<<s<<" ";

    for(int it:adj[s]){
        if(visited[it]==false){
            DFSrec(adj,visited,it);
        }
    }
}

void DFS(vector<vector<int> > adj, int v){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            DFSrec(adj,visited,i);
        }
    }
}

int main() 
{ 
	int V=5;
	vector<vector<int> > adj(V);
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);

	cout << "Following is Depth First Traversal for disconnected graphs: "<< endl; 
	DFS(adj,V); 

	return 0; 
} 
*/

#include<iostream> 
#include<vector>
using namespace std; 

void DFSRec(vector<vector<int> > adj, int s, vector<bool> &visited) 
{ 	
    visited[s]=true;
    cout<< s <<" ";
    
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

void DFS(vector<vector<int> > adj, int V){
    vector<bool> visited(V,false); 
	/*for(int i = 0;i<V; i++) 
		visited[i] = false;*/
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            DFSRec(adj,i,visited);
    }
}

void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<vector<int> > adj(V);
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);

	cout << "Following is Depth First Traversal for disconnected graphs: "<< endl; 
	DFS(adj,V); 

	return 0; 
} 
