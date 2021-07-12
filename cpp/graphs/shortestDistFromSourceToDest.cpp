#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 1000

void add_edge(vector<vector<int> > &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool shortestPath(vector<vector<int> > &adj, int s, int d, int v, vector<int>& pred, vector<int>& dist){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        dist[i]=INF;
        pred[i]=-1;
    }
    queue<int> q;
    q.push(s);
    visited[s]=true;
    dist[s]=0;

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i: adj[curr]){
            if(visited[i]==false){
                q.push(i);
                visited[i]=true;
                dist[i]=dist[curr]+1;

                if(i==d){
                    return true;
                }
            }
        }
    }
    return false;
}

void printShortestDistance(vector<vector<int> > &adj, int s, int d, int v){
    vector<int> pred(v,-1);
    vector<int> dist(v,0);

    if(shortestPath(adj,s,d,v,pred,dist)==false){
        cout<<" destination node not connected to the source"<<endl;
        return;
    }

    //now we find the shortest path using the pred (predecessors) from
    //destination node to the source

    vector<int> path;
    int crawl=d;
    path.push_back(crawl);
    while(pred[crawl]!=-1){
        path.push_back(pred[crawl]);
        crawl=pred[crawl];
    }

    cout<<"path length is "<<dist[d]<<endl;

    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }

}

int main(){
    int v=8;
    vector<vector<int> > adj(v);

    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    int source = 0, dest = 7;
    printShortestDistance(adj, source, dest, v);
    return 0;

}