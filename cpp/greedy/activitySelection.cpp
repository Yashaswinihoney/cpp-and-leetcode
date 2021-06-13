#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
    return(a.second<b.second);
}
int maxActivity(vector<pair<int,int> > v, int n){
    sort(v.begin(), v.end(),comp);
    //sorting the pairs according to their seconds
    int res=1;
    int prev=0;
    for(int i=1;i<n;i++){
        if(v[i].first>=v[prev].second){
            res++;
            prev=i;
        }
    }
    return res;
}
int main(){
    //pair<int, int> arr[]={make_pair(12,25),make_pair(10,20),make_pair(20,30)};
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    
    cout<<maxActivity(v,n);
    return 0;
}