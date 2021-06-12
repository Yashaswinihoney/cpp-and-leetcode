#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int i,j;
    for(i=0,j=t.length()-1;i<s.length(),j>=0;i++,j--){
        if(s[i]!=t[j]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}