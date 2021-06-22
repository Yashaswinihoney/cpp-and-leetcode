#include<iostream>
#include<set>
#include<string>
using namespace std;
int main(){
    char c;
    set<char> res;
    while(cin>>c){
        if(isalpha(c)) res.insert(c); 
    }
    cout<<res.size();
    return 0;
}