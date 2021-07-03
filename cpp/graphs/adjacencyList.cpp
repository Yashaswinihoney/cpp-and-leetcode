#include<iostream>
#include<vector>
using namespace std;

//for adding edges for undirected graphs
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//printing the graph
void printGraph(vector<vector<int> > adj, int v){
    /*for (int i = 0; i < v; i++) 
    { 
        for (int x : adj[i]) 
           cout << x <<" "; 
        cout<<"\n"; 
    }*/
    
    for(int i=0;i<v;i++){
        /*for(int j=0;i<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }*/
        for(auto x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int v=4;
    vector<vector<int>  > adj(v);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    printGraph(adj,4);
    return 0;
}