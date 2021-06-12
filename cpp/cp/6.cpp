#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int n=0;
    while((pow(3,n)*a)<=(pow(2,n)*b)){
        n++;
    }
    cout<<n;
    return 0;
}