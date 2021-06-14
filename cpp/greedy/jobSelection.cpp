#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<deque>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
    return(a.second>b.second);
}
vector<pair<int, int> > result(vector<pair<int, int> > v, int n){
    sort(v.begin(),v.end(),comp);
    vector<pair<int, int> > res;
    res.push_back(v[0]);
    int prev=res[0].first;
    for(int i=1;i<n;i++){
        int s=res.size();
        for(int j=0;j<s;j++){
            if(res[j].first==v[i].first) continue;
        }
        res.push_back(v[i]);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > v;
    for(int i=0;i<n;i++){
        int j,p;
        cin>>j>>p;
        v.push_back(make_pair(j,p));
    }
    vector<pair<int, int> > res=result(v,n);
    for( auto i:res){
        cout<<i.first<<" "<<i.second<<" ";
    }
    return 0;
}