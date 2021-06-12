#include<iostream>
#include<queue>
#include<string>
using namespace std;

void printN(int n){
    queue<string> q;
    q.push("5");
    q.push("6");

    for(int i=0;i<n;i++){
        cout<<q.front()<<endl;
        q.push(q.front()+"5");
        q.push(q.front()+"6");
        q.pop();
    }
}

int main(){
    int n=5;
    printN(8);
    return 0;
}
