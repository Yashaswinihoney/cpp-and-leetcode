#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;
bool first(pair<int, int> a, pair<int, int> b){
    double r1=(a.first/a.second);
    double r2=b.first/b.second;
    return(r1<r2);
}
int cost(vector<pair<int, int> > v, int cap,int n){
    sort(v.begin(),v.end(),first);
    int res=0;
    int curr_cap=cap;
    for(int i=0;i<n;i++){
        if(v[i].first<curr_cap){
            curr_cap-=v[i].first;
            res+=v[i].second;
        }
        else{
            res+=int(v[i].second*float(curr_cap/v[i].first));
            return res;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int cap;
    cin>>cap;
    vector<pair<int, int> > v;
    for( int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    cout<<cost(v,cap,n);
    return 0;
}