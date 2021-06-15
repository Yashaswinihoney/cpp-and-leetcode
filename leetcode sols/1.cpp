#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
bool mem(pair<int, int> a, pair<int, int>b){
    return(a.second<=b.second);
}
vector<pair<int, int> > result(vector<pair<int, int> > a, vector<pair<int,int> > b,int n){
    sort(a.begin(),a.end(),mem);
    sort(b.begin(),b.end(),mem);
    int i=a.size()-1;
    int j=0;
    vector<pair<int, int> > res{};
    while(i>=0&&j<b.size()){
        int d=100;
        if(a[i].second+b[j].second=n){
            if(d>=abs(n-(a[i].second+b[j].second))){
                res.pop_back();
                res.push_back(make_pair(a[i].first,b[j].first));
                d=abs(n-(a[i].second+b[j].second));
                i--; j++;
            }
        }
        if(a[i].second+b[j].second<n&&d>abs(n-(a[i].second+b[j].second))){
            res.pop_back();
            res.push_back(make_pair(a[i].first,b[j].first));
            d=abs(n-(a[i].second+b[j].second));
            j++;
        }
        else{
            i--;
        }
    }
    if(res.size()==0){
        return{()};
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > a{};
    vector<pair<int, int> > b;
    int x,y;
    /*while((cin>>x)&&(cin>>y)){
        a.push_back(make_pair(a,b));
    }*/

}