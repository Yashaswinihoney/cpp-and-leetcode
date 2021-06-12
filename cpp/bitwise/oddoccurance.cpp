#include<iostream>
using namespace std;
int odd(int arr[], int n){
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    return res;
}
int main(){
    int arr[]={1,2,2,1,1,4,4,5,5,6,6};
    cout<<odd(arr,11);
    return 0;
}