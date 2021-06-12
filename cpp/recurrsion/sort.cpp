#include<iostream>
using namespace std;

bool sorted(int arr[], int n){

    if(n==1){
        return true;
    }

    bool restArray=sorted(arr+1, n-1);
    if(arr[0]<arr[1]&&restArray){
        return true;
    }
}
int main(){
    int arr[]={1,2,3,8,7};
    cout<<sorted(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}