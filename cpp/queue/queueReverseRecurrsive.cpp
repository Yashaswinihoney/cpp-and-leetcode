#include<iostream>
#include<queue>
using namespace std;
void display(queue<int> q){
    while (!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<endl;
}

void reverse(queue<int> &q){
    if(q.empty()){
        return ;
    }
    int x=q.front();
    q.pop();
    reverse(q);
    q.push(x);
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