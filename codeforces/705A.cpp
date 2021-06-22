#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string o="I hate ";
    string e="I love ";
    string t="that ";
    string res="";
    int i=1;
    while(i<=n){
        (i%2==0)?(res+=e):(res+=o);
        if(i!=n) res+=t;
        i++;
    }
    res+="it";
    cout<<res;
    return 0;
}