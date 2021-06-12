#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void display(queue<int> Q){
    while(!Q.empty()){
        cout<<Q.front()<<endl;
        Q.pop();
    }
    cout<<endl;
}

void reverse(queue<int> &q){
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }   
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    display(q);
    reverse(q);
    display(q);
    return 0;
}