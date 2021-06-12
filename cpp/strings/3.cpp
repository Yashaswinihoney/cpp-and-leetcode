#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    char c=s[0];
    s[0]=toupper(c);
    cout<<s;
    return 0;
}
