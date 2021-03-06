#include<iostream>
#include <vector>
using namespace std;

#define N 4 
  
int board[N][N];  

void printsol(int board[N][N]){
    for(int i = 0; i <N;i++){
        for(int j = 0; j <N;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

bool isSafe(int row, int col){

    //we just have to check before the region
    //where [row][col] 

    //checking in the same row
    for(int i=0;i<col;i++){
        if(board[row][i]) 
            return false;
    }

    //now checking in the upper diagonal before the point
    for(int i=row, j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]) 
            return false;
    }

    //now checking in the lower diagonal after the point
    for(int i=row, j=col;j>=0&&i<N;i++,j--){
        if(board[i][j]) 
            return false;
    }

    return true;
}

bool solverec(int col){
    if(col==N) 
        return true;

    for(int i=0;i<N;i++){

        if(isSafe(i,col)){
            board[i][col]=1;

            if(solverec(col+1)){
                return true;
            }

            board[i][col]=0;
        }
    }

    return false;
}

bool solve(){
    if(solverec(0)==false){
        cout<<"solution does not exist";
        return false;
    }

    printsol(board);
    return true;
}
int main(){
    solve();
    return 0;
}

