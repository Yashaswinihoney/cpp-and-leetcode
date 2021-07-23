#include <iostream>
#include <string.h>
using namespace std;

int memo[1000][1000];

int lcs(string A, string B, int m, int n){
    
}

int main(){
    int m=4, n=3;
    string A="AXYZ";
    string B="XYZ";
    memset(memo,-1,sizeof(memo));
    cout<<lcs(A,B,m,n);
    return 0;
}