#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int i, int key){

    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    firstOcc(arr,n,i+1,key);
}

int lastOcc(int arr[], int n, int i, int key){
    int restArray=lastOcc(arr,n,i+1,key);
    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}