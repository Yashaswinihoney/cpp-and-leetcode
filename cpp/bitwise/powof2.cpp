#include<iostream>
using namespace std;
bool powofTwo(int n){
    if(n==0){
        return false;
    }
    return ((n&(n-1))==0);
}
int main(){
    cout<<powofTwo(2)<<endl;
    cout<<powofTwo(4)<<endl;
    cout<<powofTwo(5)<<endl;
    cout<<powofTwo(7)<<endl;
    return 0;        
}