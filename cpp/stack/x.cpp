#include<iostream>
using namespace std;
unsigned int get(unsigned int arr[], int len){
    unsigned int re=0;
    for(int i=0;i<len;i++){
        re=(re<arr[i])?re:arr[i];
    }
    return re;
}
int fun(int n){
    int r=0;
    while(n!=0){
        r=n%10;
        r=r*10+r;
    n=n/10;
    }
    return r;
}
int main(){
    cout<<fun(12489);
    return 0;

}