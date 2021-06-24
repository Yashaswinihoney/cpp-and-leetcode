#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int res;
        int n;
        cin>>n;
        res=n;
        n--;
        while(n--){
            res=res&n;
            if(res==0){
                cout<<n+1<<endl; break;
            }
        }
    }
    return 0;
}