#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;
class Graph{
    public:
    int V;
    list<int>* adjlist;

    Graph(int v){
        V=v;
        adjlist=new list<int>[V];
    }
    void DFS(int v, vector<bool>& visited, int count);
    void addEdge(int u, int v);
    int findMother();
};

void Graph:: addEdge(int u, int v){
    adjlist[u].push_back(v);
}

void Graph::DFS(int v, vector<bool>& visited, int count){
    visited[v]=true;
    count++;

    for(auto it=adjlist[v].begin();it!=adjlist[v].end();it++){
        if(visited[*it]==false){
            DFS(*it,visited,count);
        }
    }
}

int Graph::findMother(){
    vector<bool> visited(V,false);

    int v=-1;
    int count=0;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            DFS(i,visited,count);
            if(count==V){
                v=i;
            }
            cout<<count;
            //v=0;
        }
    }
    return v;
}

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,3);
    g.addEdge(4,1);
    g.addEdge(6,4);
    g.addEdge(5,6);
    g.addEdge(5,2);
    g.addEdge(6,0);

    cout<<"mother vertex "<<g.findMother();
    return 0;
}
