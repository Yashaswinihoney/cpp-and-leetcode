#include <iostream>
#include <vector>
using namespace std;
int tower(int n, int res, char A, char B, char C){
    if(n==1){
        res=1;
        return res;
    }

    res+=tower(n-1,res,A,C,B);
    res+=tower(n-1,res,B,A,C);
    return res;
}
int main(){
    int n=5;
    int res=0;
    char A, B, C;
    cout<<tower(n,res,A,B,C)<<endl;
    return 0;
}