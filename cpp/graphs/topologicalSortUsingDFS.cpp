#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void addEdge(vector<vector<int> >& adj, int u, int v){
    adj[u].push_back(v);
}

void DFS(vector<vector<int> > adj, int s, vector<bool>& visited, stack<int>& st){
    visited[s]=true;
    for(int x:adj[s]){
        if(visited[x]==false){
            DFS(adj,x,visited,st);
        }
    }
    st.push(s);
}

void topologicalSort(vector<vector<int> >adj , int V){
    vector<bool> visited(V,false);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            DFS(adj,i,visited,st);
        }
    }
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        cout<<curr<<" ";
    }
}

int main(){
    int V=5;
    vector<vector<int> > adj(V);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    topologicalSort(adj, V);
    return 0;
}