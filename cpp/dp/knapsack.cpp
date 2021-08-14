#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int knapsack(int W, int wt[], int va[], int n){
    int dp[n+1][W+1];
    memset(dp, 0, sizeof(dp));
}
int main(){
    int val[4]={10,40,30,50};
    int wt[4]={5,4,6,3};
    int W=10;
    cout<<knapsack(W,wt,val,4);
    return 0;	
}