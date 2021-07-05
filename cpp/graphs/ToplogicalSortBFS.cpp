//also called kahn's algorithm
//its bfs based
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void addEdge(vector<vector<int> >&adj, int u, int v){
    adj[u].push_back(v);
}

void topologicalSort(vector<vector<int> > adj, int V){
    vector<int> in_degree(V,0);
    for(int i=0;i<V;i++){
        for(auto x: adj[i]){
            in_degree[x]++;
        }
    }

    queue<int> q;

    //pushing the elements into the queue whose indegrees are zer0
    //or the elements who do not have any dependencies
    for(int i=0;i<V;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";

        for(int x:adj[u]){
            if(--in_degree[x]==0){
                q.push(x);
            }
        }
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