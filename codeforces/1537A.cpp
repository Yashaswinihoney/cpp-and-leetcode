#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++){
            int nums;
            cin>>nums;
            sum+=nums;
        }
        if(sum==n){
            cout<<0<<endl; 
        }
        else{
            if(sum<0){
                cout<<1<<endl;
            }
            if(sum>0&&sum<n){
                cout<<n-sum<<endl;
            }
            else if(sum>0&&sum>n){
                cout<<sum-n<<endl;
            }
        }
    }
    return 0;
}