#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void addEdge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
}

bool checkCycle(vector<vector<int> > adj, int V){
    vector<int> in_degree(V,0);
    for(int i=0;i<V;i++){
        for(auto x:adj[i]){
            in_degree[x]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    
    int count=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();

        for(int x: adj[curr]){
            if(--in_degree[x]==0){
                q.push(x);
            }
        }
        count++;
    }
    return(count==V);
}

int main(){
    int V=5;
    vector<vector<int> > adj(V);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    if(checkCycle(adj, V)) cout<<"cycle"<<endl;
    else cout<<"no cycle"<<endl;
    return 0;
}