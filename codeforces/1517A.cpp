#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<2050) cout<<-1<<endl;
        else if(n%2050==0){
            int res=n/2050;
            if(res%10==0) cout<<1<<endl;
            else{
                cout<<res%10<<endl;
            }
        }
    }
    return 0;
}