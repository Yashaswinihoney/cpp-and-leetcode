#include<iostream>
#include <vector>
using namespace std; 
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
}

bool cycle(vector<vector<int> > adj, int s, vector<int>& colors){
    colors[s]=1;
    for(int i:adj[s]){
        if(colors[i]==0){
            if(cycle(adj,i,colors)) return true;
        }
        else{
            if(colors[i]==1) return true;
        }
    }
    colors[s]=2;
    return false;
}

bool isCycle(vector<vector<int> > adj, int v){
    vector<int> colors(v,0);
    for(int i=0;i<v;i++){
        if(colors[i]==false){
            if(cycle(adj,i,colors)) return true;
        }
    }
    return false;
}

int main(){
    int v=4;
    vector<vector<int> > adj(v);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,2,3);
    addEdge(adj,3,3);

    isCycle(adj,v)?cout<<"yes":cout<<"no";
    return 0;
}