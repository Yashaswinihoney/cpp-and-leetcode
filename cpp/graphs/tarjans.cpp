// used to find strongly connnected components
#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#define NIL -1 
using namespace std; 


class Graph 
{ 
    public: 

	int V; 
	list<int> *adj; 

	void SCCUtil(int u, vector<int> &disc, vector<int>& low, stack<int>& st, vector<bool>& stackMember); 
	Graph(int V); 
	void addEdge(int v, int w); 
	void SCC(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
} 

static int t=0;
void Graph::SCCUtil(int u, vector<int> &disc, vector<int>& low, stack<int>& st, vector<bool>& stackMember){
	disc[u]=low[u]=++t;
	st.push(u);
	stackMember[u]=true;

	for(auto i=adj[u].begin();i!=adj[u].end();i++){
		int v=*i;

		if(disc[v]==-1){
			SCCUtil(v,disc,low,st,stackMember);

			low[u]=min(low[u],low[v]);
		}

		else if(stackMember[v]==true){
			low[u]=min(low[u],disc[v]);
		}
	}

	int w=0;
	if(low[u]==disc[u]){
		while(st.top()!=u){
			w=st.top();
			cout<<w<<" ";
			stackMember[w]=false;
			st.pop(); 
		}

		w=st.top();
		cout<<w<<endl;
		stackMember[w]=false;
		st.pop();  
	}
}

void Graph::SCC(){
    vector<bool> stackMember(V,false);
    vector<int> disc(V,NIL);
    vector<int> low(V,NIL);
    stack<int> st;

    for(int i=0;i<V;i++){
        if(disc[i]==NIL){
            SCCUtil(i,disc,low,st,stackMember);
        }
    }
}

int main() 
{ 
	cout << "SCCs in the graph \n"; 
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	g.SCC(); 

	return 0; 
} 
