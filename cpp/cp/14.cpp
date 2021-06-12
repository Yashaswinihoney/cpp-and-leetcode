#include<iostream>
using namespace std;
int main(){
int n,a=0,d=0;
string s;
cin>>n>>s;
for(char c:s)
    c=='A' ? a++ : d++;
cout<<(a==d? "Friendship":a>d ? "Anton":"Danik");
return 0;
}

