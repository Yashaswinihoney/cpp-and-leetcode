#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        unordered_set<int> s;
        int t=4;
        while(t--){
            int a;
            cin>>a;
            s.insert(a);
        } 
        int S=s.size();
        cout<<(S/2)<<endl;
    }
    return 0;
}