#include <iostream>
#include <vector>
using namespace std;
void friends(vector<int> A, int n, vector<int>& res){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]%A[j]==0||A[j]%A[i]==0){
                res[i]++;
                res[j]++;
            }
        }
    }
}

int main(){
    vector<int> A;
    char c;
    for(int i=0;;i++){
        cin>>c;
        if(c=='\n'){
            break;
        }
        int x = c - '0';// typecasting char into integer.
        A.push_back(x);
    }
    /*int a;
    while(cin>>a){
        A.push_back(a);
    }*/
    int n=A.size();
    vector<int> res(n,0);
    friends(A,n,res);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}