#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

void kClosest(vector<int> v, int n, int k, int x){
    priority_queue<pair<int, int> > pq;
    for(int i=0;i<k;i++){
        pq.push(make_pair(abs(v[i]-x),i));
    }
    for(int i=k;i<n;i++){
        int diff=abs(v[i]-x);
        if(diff<pq.top().first){
            pq.pop();
            pq.push(make_pair(diff,i));
        }
    }
    while(!pq.empty()){
        cout<<v[pq.top().second]<<" ";
        pq.pop();
    }
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(5);
    v.push_back(40);
    v.push_back(38);
    v.push_back(80);
    v.push_back(70);
    int n=v.size();
    int x=35;
    int k=3;
    kClosest(v,n,k,x);
    return 0;
}