#include<iostream>
#include<string>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    string res="";
    for(int i=0;i<a.length();i++){
        (a[i]!=b[i])?(res.push_back('1')):(res.push_back('0'));
    }
    cout<<res;
    return 0;
}