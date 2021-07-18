#include<iostream>
#include <vector>
using namespace std;

#define N 4 
  
int board[N][N];  

void printsol(int board[N][N]){
    for(int i = 0; i <N;i++){
        for(int j = 0; j <N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solverec(int col){

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