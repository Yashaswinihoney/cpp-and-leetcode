#include<iostream>
#include<set>
using namespace std;
int main(){
    int n=4;
    set<int> s;
    while(n--){
        int a;
        cin>>a;
        s.insert(a);
    }
    cout<<(4-s.size());
    return 0;
}