#include<iostream>
#include<set>
#include<unordered_set>
#include<vector>
using namespace std;
int countDistinct(vector<int> a,int n){
    unordered_set<int> res(a.begin(),a.end());
    return(res.size());
}
int main(){
    int n=8;
    //cin>>n;
    vector<int> a;
    a.push_back(4);
    a.push_back(4);
    a.push_back(5);
    a.push_back(5);
    a.push_back(6);
    a.push_back(2);
    cout<<countDistinct(a,n);
    return 0;
    //unordered_set<int> a{1,2,3,4,6,6}
}