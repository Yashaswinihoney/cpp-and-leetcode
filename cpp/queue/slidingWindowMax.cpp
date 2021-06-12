//using deque
#include<iostream>
#include<deque>
#include<iterator>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int>:: iterator i;
    for(i=a.begin();i!=a.end();i++){
        cin>>*i;
    }

    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!q.empty()&& a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    for(int i=k;i<n;i++){
        if (q.front()==i-k)
        {
            q.pop_back();  
        }
        while(!q.empty() && a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);  
    }

    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}