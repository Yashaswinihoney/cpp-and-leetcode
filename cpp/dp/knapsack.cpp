#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int knapsack(int W, int wt[], int val[], int n){
    int dp[n+1][W+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
    }

    return dp[n][W];
}
int main(){
    int val[4]={10,40,30,50};
    int wt[4]={5,4,6,3};
    int W=10;
    cout<<knapsack(W,wt,val,4);
    return 0;	
}