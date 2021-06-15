#include<iostream>
#include<unordered_map>
#include<vector>
#include<iterator>
using namespace std;
void freq(vector<int> v,int n){
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[v[i]]++;
    }
    unordered_map<int,int>:: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    
}
int main(){
    int n=8;
    vector<int> a;
    a.push_back(4);
    a.push_back(4);
    a.push_back(5);
    a.push_back(5);
    a.push_back(6);
    a.push_back(2);
    a.push_back(7);
    a.push_back(6);
    freq(a,n);
    return 0;
    //unordered_set<int> a{1,2,3,4,6,6}
}