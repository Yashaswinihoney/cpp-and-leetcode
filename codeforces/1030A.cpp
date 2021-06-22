#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(a!=0){
            cout<<"HARD"; 
            return 0;
        }
    }
    cout<<"EASY";
    return 0;
}