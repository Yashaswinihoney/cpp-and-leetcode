#include <iostream>
#include <string.h>
using namespace std;

int getCount(int coins[], int n, int sum){
    int dp[sum+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=1;
    }

    for(int i=0;i<=sum;i++){
        dp[i][0]=0;
    }

    for(int i=0;i<=sum;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=dp[i][j-1];

            if(coins[j-1]<=sum){
                dp[i][j]+=dp[i-coins[j-1]][j];
            }
        }
    }
}

int main() {

    int coins[]={1, 2, 3}, sum=4, n=3;

    cout<<getCount(coins, n, sum);
    return 0;
}