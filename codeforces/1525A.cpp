#include<iostream>
#include<cmath>
using namespace std;
int lcm(int a,int b){
    int m=max(a,b);
    m=m/2;
    int res=1;
    for(int i=1;i<=min(a,b)&&i<=m;i++){
        if(a%i==0&&b%i==0) res=res*i;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        if(k==100){
            cout<<1<<endl;
        }
        else{
            int l=lcm(k,100-k);
            cout<<(k/l)+((100-k)/l)<<endl;
        }
    }
    return 0;
}