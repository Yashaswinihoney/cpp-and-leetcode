/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cap=0;
    int rem=0;
    while(n--){
        int a,b;
        cin>>a>>b;
        int rem=rem-a+b;
        if(cap<=rem){
            cap=rem;
        }
    }
    cout<<cap;
    return 0;
}*/

#include<iostream>
using namespace std;
int main(){
    int a,b,c=0,s=0,n;
    cin>>n;
    while(cin>>a>>b){
        c+=b-a;
        if(c>s) 
            s=c;
    }
    cout<<s;
}