#include<iostream>
#include<vector>
using namespace std;

vector <int> v(1000000,-1);

int fib(int n){
    if(v[n]==-1){
        int res;

        if(n==0||n==1){
            return n;
        }
        else{
            res=fib(n-1)+fib(n-2);
        }
        v[n]=res;
    }
    return v[n];
}

int main(){
    int n=5;
    cout<<fib(n)<<endl;
    return 0;
}