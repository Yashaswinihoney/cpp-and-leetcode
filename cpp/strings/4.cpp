#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count =0;
    char c=s[0];
    int i=0;
    while(i<s.length()){
        if(c==s[i+1]){
            c=s[i+1];
            count++;
            i++;
        }
        else{
            c=s[i+1];
            i++;
        }
    }
    cout<<count;
    return 0;

}