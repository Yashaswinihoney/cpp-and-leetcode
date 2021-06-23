#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iterator>
using namespace std;
int main(){
    int num;
    cin>>num;
    while(num--){
        int n;
        cin>>n;
        vector<int> v(n);
        bool res=true;
        for(int i=0;i<n;i++){
            cin>>v[i];
            //v.push_back(a);
        }
        for(int i=0;i<v.size();i++){
            if(v[i]*v[i+1]<0){
                res=false;
                break;
            }
            if(count(v.begin(),v.end(),abs(v[i]-v[i+1]))==0){
                v.push_back(abs(v[i]-v[i+1]));
            }
        }
        if(res==true){
            cout<<"YES"<<endl;
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}