#include<iostream>
#include<vector>
#include<cmath>
#define INF 100
#define V 4
using namespace std;

//we use adjacency matrix representation 
//for the prims algorithms

int primMST(int graph[V][V]){

    //initialising distances of all the keys to max
    vector <int> key(V,INF);
    vector<bool> mSet(V,false);

    //coz we start traversing from index = 0
    key[0]=0;
    int res=0;

    for(int count=0;count<V;count++){
        int u=-1;

        //to find the key with the minimum distance
        for (int i = 0; i < V; i++)
        {
            //for the keys that are not the mst and dist of i is less then dist of u
            //or u = -1, i.e. we have just started traversing
            if(!mSet[i]&&(u==-1||key[i]<key[u])){
                u=i;
            }
        }
        mSet[u]=true;
        res+=key[u];

        //updating the min distance of the keys from the picked key
        for(int v=0;v<V;v++){

            //only if u & v are connected and v is not alredy in the mst
            if(graph[u][v]!=0&&mSet[v]==false){

                //updating only if the new dist is less than the dist alredy present
                key[v]=min(key[v],graph[u][v]);
            }
        }        
    }
    return res;
}

int main(){
    int graph[V][V]={{0,5,8,0},{5,0,10,15},{8,10,0,20},{0,15,20,0}};
    cout<<primMST(graph);
    return 0;
}