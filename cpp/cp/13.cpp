#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    (s==t)?(cout<<"YES"):(cout<<"NO");
    return 0;
}