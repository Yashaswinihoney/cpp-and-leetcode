#include<iostream>
#include<map>
using namespace std;
/*bool comp(pair<int,int> a, pair<int,int> b){
    return(a.second<=b.second);
}*/
int main(){
    long int t,n,a;
    cin>>t;
    while(t--){
        cin>>n;
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>a;
            m[a]++;
        }
        cout<<n-m.begin()->second<<endl;
    }
    return 0;
}