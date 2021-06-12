#include<iostream>
using namespace std;
//method 1
/*void kbit(int n, int k){
    if(n&(1<<(k-1)))
        cout<<"yes";
    else{
        cout<<"no";
    }
}*/

//method2
void kbit(int n, int k){
    if((n>>(k-1))&1){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}

int main(){
    kbit(8,3);
    return 0;
}