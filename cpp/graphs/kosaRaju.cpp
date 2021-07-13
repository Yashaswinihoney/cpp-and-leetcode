//to print sets of strongly connected components
//in new lines
#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

class  Graph{
    public:
    int V;
    list<int> *adj;

    void topologicalSort(int v, vector<bool>& visited, stack<int>& st);
    
    void dfs(int v, vector<bool>& visited);

    Graph(int v);
    void addEdge(int v, int w);

    void printSSC();

    Graph transpose();
};

Graph:: Graph(int v){
    this->V = v;
    adj= new list<int>[V];
}

void Graph:: dfs(int s, vector<bool>& visited){
    visited[s]=true;
    cout<<s<<" ";
    for(int i: adj[s]){
        if(visited[i]==false){
            dfs(i,visited);
        }
    }
}

void Graph:: addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph:: topologicalSort(int v, vector<bool>& visited, stack<int>& st){
    visited[v]=true;

    for(int i:adj[v]){
        if(visited[i]==false){
            topologicalSort(i,visited,st);
        }
    }
    st.push(v);
}

Graph Graph:: transpose(){
    Graph gr(V);
    for(int i=0;i<V;i++){
        for(int x:adj[i]){
            gr.adj[x].push_back(i);
        }
    }
    return gr;
}

void Graph::printSSC(){
    vector<bool> visited(V,false);
    stack<int> st;

    for(int i=0;i<V;i++){
        if(visited[i]==false){
            topologicalSort(i,visited,st);
        }
    }

    Graph gr=transpose();

    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    while(!st.empty()){
        int curr=st.top();
        st.pop();

        if(visited[curr]==false){
            dfs(curr,visited);
            cout<<endl;
        }
    }
}

int main(){
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);

    g.printSSC();

    return 0;
}