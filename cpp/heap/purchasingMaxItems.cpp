#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int maxEle(vector<int> v, int n, int sum){
    priority_queue<int, vector<int>, greater<int> >pq(v.begin(),v.end());
    int res=0;
    for(int i=0;i<n;i++){
        if(pq.top()<=sum){
            res++;
            sum-=pq.top();
            pq.pop();
        }
        if(pq.top()>sum) return res;
    }
    return res;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(12);
    v.push_back(5);
    v.push_back(111);
    v.push_back(200);
    int n=sizeof(v)/sizeof(v[0]);
    int sum=10;
    cout<<maxEle(v,n,sum);
    return 0;
}