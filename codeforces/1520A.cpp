#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string st;
        cin>>st;
        set<char> s;
        bool f=true;
        for(int i=0;i<st.size();i++){
            if(s.empty()||s.find(st[i])==s.end()){
                s.insert(st[i]);
            }
            else if(!s.empty()&&st[i-1]!=st[i]&&s.find(st[i])!=s.end()){
                f=false;
                break;
            }
        }
        (f==true)?(cout<<"YES"<<endl):(cout<<"NO"<<endl);
    }
    return 0;
}