#include <iostream>
#include <vector>
using namespace std;
int res;
void tower(int n, char A, char B, char C){
    if(n==1){
        //res+=1;
        return;
    }

    res+=1;
    tower(n-1,A,C,B);
    res+=1;
    tower(n-1,B,A,C);
    //return res;
}
int main(){
    int n=3;
    res=0;
    char A, B, C;
    
    tower(n,A,B,C);
    cout<<res;
    return 0;
}