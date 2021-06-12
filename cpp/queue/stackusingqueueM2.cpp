//Method 2
//when pop is costly
#include<iostream>
#include<queue>
using namespace std;
class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(){
        N=0;
    }

    void push(int val){
        q1.push(val);
        N++;
    }

    int size(){
        return N;
    }

    int pop(){
        if(N==0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int del=q1.front();
        q1.pop();
        swap(q1,q2);
        N--;
        return del;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        return q1.back();
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    st.pop();
    st.pop();
    cout<<st.size()<<endl;
    return 0;
}