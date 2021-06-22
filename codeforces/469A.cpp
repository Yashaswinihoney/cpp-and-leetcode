#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<int> res;
    int k;
    cin>>k;
    while(k--){
        int a;
        cin>>a;
        res.insert(a);
    }
    cin>>k;
    while(k--){
        int a;
        cin>>a;
        res.insert(a);
    }
    if(res.size()==n){
        cout<<"I become the guy.";
    }
    else{
        cout<<"Oh, my keyboard!";
    }
    return 0;
}