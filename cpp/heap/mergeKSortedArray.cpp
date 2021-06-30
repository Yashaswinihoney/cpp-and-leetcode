#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Triplet{
    public:
    int v;
    int aPos;
    int vPos;
    Triplet(int val, int APos, int VPos){
        v=val;
        aPos=APos;
        vPos=VPos;
    }
};

//Comparator class for the priority queue
class MyComp{
    public:
    bool operator()(Triplet &a, Triplet &b){
        return(a.v>b.v);
    }
};
vector<int> merge(vector<vector<int> >& v){
    vector<int> res;
    priority_queue<Triplet, vector<Triplet>,MyComp> pq;
    for(int i=0;i<v.size();i++){
        Triplet t(v[i][0],i,0);
        pq.push(t);
    }
    while (!pq.empty())
    {
        Triplet curr=pq.top();
        pq.pop();
        res.push_back(curr.v);
        int ap=curr.aPos;
        int vp=curr.vPos;
        if(vp+1<v[ap].size()){
            Triplet t(v[ap][vp+1],ap,vp+1);
            pq.push(t);
        }
    }
    return res;
}
int main(){
    vector<vector<int> > v;
    vector<int> a;
    a.push_back(5);
    a.push_back(10);
    vector<int> b;
    b.push_back(4);
    b.push_back(9);
    vector<int> c;
    c.push_back(6);
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    vector<int> res=merge(v);
    for(auto it: res){
        cout<<it<<endl;
    }
    return 0;
}