#include<iostream>
#include<cmath>
using namespace std;
int lcm(int a,int b){
    if(a==b) return a;
    if(a>b) return  lcm(a-b,b);
    return lcm(a,b-a);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        if(k==100) cout<<1<<endl;
        else{
            int l=lcm(k,100-k);
            cout<<(k/l)+((100-k)/l)<<endl;
        }
    }
    return 0;
}