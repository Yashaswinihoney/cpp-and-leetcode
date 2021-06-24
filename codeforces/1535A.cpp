#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n=4;
        vector<int> v1(n);
        for(int i=0;i<n;i++){
            cin>>v1[i];
        }
        bool f=true;
        vector<int> v2=v1;
        sort(v2.begin(),v2.end());
        int a=v2[3], b=v2[2];
        for(int i=0;i<3;i++){
            if(i!=1&&((v1[i]==a&&v1[i+1]==b)||(v1[i]==b&&v1[i+1]==a))){
                f=false;
                break;
            }
        }
        if(f==true){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}