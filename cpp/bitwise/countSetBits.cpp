#include<iostream>
using namespace std;
//method 1
/*int setBits(int n){
    int count=0;
    for(int i=0;i<32;i++){
        if(n&(1<<i)){
            count++;
        }
    }
    return count;
}*/

//method 2 wow
int setBits(int n){
    int res=0;
    while(n>0){
        n=n&(n-1);
        res++;
    }
    return res;
}
int main(){
    cout<<setBits(3)<<endl;
    cout<<setBits(4)<<endl;
    cout<<setBits(0)<<endl;
    return 0;
}