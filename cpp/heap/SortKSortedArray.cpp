#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void sortK(vector<int> &a, int n, int k){
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0;i<=k;i++){
        pq.push(a[i]);
    }
    int index=0;
    for(int i=k+1;i<n;i++){
        a[index++]=pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while (!pq.empty())
    {
        a[index++]=pq.top();
        pq.pop();
    }
    
}

void printA(vector<int> a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int k=3;
    vector<int> a;
    a.push_back(2);
    a.push_back(6);
    a.push_back(3);
    a.push_back(12);
    a.push_back(56);
    a.push_back(8);
    int n=sizeof(a)/sizeof(a[0]);
    sortK(a,n,k);
    printA(a,n);
    return 0;
}