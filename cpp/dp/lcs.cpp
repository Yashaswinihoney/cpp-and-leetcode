#include <iostream>
#include <string.h>
using namespace std;

int memo[1000][1000];

int lcs(string A, string B, int m, int n){
    if(memo[m][n]!=-1){
        return memo[m][n];
    }
    if(m==0||n==0) return 0;
    else{
        if(A[m]==B[n]){
            memo[m][n]=1+lcs(A,B,m-1,n-1);
        }
        else{
            memo[m][n]=max(lcs(A,B,m,n-1),lcs(A,B,m-1,n));
        }
    }
    return memo[m][n];
}

int main(){
    int m=4, n=3;
    string A="AXYZ";
    string B="XYZ";
    memset(memo,-1,sizeof(memo));
    cout<<lcs(A,B,m,n);
    return 0;
}