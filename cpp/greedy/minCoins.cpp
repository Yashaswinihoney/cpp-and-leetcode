#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int minCoins(vector<int> v, int n, int amnt){
    sort(v.begin(),v.end());
    int res=0;
    for(int i=n-1;i>=0;i--){
        if(v[i]<=amnt){
            int f=floor(amnt/v[i]);
            res=res+f;
            amnt=amnt-f*v[i];
        }
        if(amnt==0) break;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int amnt;
    cin>>amnt;
    vector<int> v;
    int i=0;
    while(i<n){
        int b;
        cin>>b;
        v.push_back(b);
        i++;
    }
    cout<<minCoins(v, n, amnt);
    return 0;
}