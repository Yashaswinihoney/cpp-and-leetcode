#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define V 4
#define INF 100000

vector<int> dijkstra(int graph[V][V], int src){
    vector<int> dist(V,INF);
    dist[src]=0;
    vector<bool> fin(V,false);

    for(int count=0;count<V-1;count++){
        int u=-1;
        for(int i=0;i<V;i++){
            if(fin[i]==false&&(u==-1||dist[i]<dist[u])){
                u=i;
            }
        }
        fin[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]!=0&&fin[v]==false){
                dist[v]=min(dist[v],graph[u][v]);
            }
        }
    }
    return dist;
}

int main(){
    int graph[V][V]={
        {0,50,100,0},
        {50,0,30,200},
        {100,30,0,20},
        {0,200,20,0}
    };

    for(int x: dijkstra(graph,0)){
        cout<<x<<" ";
    }
    return 0;
}