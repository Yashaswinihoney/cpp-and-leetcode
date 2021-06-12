#include<iostream>
using namespace std;
int missing(int arr[],int n){
    int res=0;
    for(int i=1;i<=n+1;i++){
        res=res^i;
    }
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    return res;
}
int main(){
    int arr[]={1,2,4,5};
    cout<<missing(arr,4);
    return 0;
}