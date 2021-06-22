#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;
    char c;
    while(n--){
        string s;
        cin>>s;
        if(c==s[0]) count++;
        c=s[1];
    }
    cout<<count+1;
    return 0;
}