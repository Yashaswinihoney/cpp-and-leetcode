#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v;
    unordered_set<int> s;
    for (int i = 0; i < n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        s.insert(a);
    }
    if(n==1||n==0) cout<<"NO HOURS"<<endl;
    int count=0;
    for(int i = 0; i < n;i++){
        if(s.find(abs(v[i]-60))!=s.end()){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}