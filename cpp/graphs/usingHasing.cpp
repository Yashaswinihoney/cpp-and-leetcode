#include<iostream>
#include<unordered_set>
using namespace std;
//this one is for undirected graphs

//representation of graphs using unordered sets
class Graph{
    public:
    int V;

    //defining the data type of the adjlist
    unordered_set<int>* adjList;

    Graph(int v){
        V=v;

        //array of unordered sets for each vertex
        adjList=new unordered_set<int>[V];
    }
};

void addEdge(Graph* graph, int src, int dest){
    graph->adjList[src].insert(dest);
    graph->adjList[dest].insert(src);
}

void printGraph(Graph* graph){
    for(int i=0;i<graph->V;i++){
        unordered_set<int> s=graph->adjList[i];
        cout<<i<<endl;

        for(auto it=s.begin();it!=s.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

void searchEdge(Graph* graph, int src, int dest){
    auto it=graph->adjList[src].find(dest);
    if(it!=graph->adjList[src].end()){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}
int main(){
    int V=5;
    Graph* graph=new Graph(V);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);

    printGraph(graph);

    searchEdge(graph,2,1);
    searchEdge(graph,0,3);
    return 0;
}
