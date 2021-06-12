/*#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(cin>>s){
    int l=s.length();
    if(l<=10){
        cout<<s<<endl;
    }
    else{
        cout<<s[0]+to_string(l)+s[l-1]<<endl;
    }
    }
    return 0;
}*/

#include<iostream>
#include<string>
using namespace std; main(){string s;cin>>s;while(cin>>s){cout<<(s.size()>10?s[0]+to_string(s.size()-2)+s[s.size()-1]:s)<<endl;}}

