#include<iostream>
using namespace std;
#define n 20
class queue{
    int* arr;
    int front;
    int back;

    public:
    queue(){
        arr=new int[n];
        front =-1;
        back=-1;
    }

    void enqueue(int x){
        if(back==n-1){
            cout<<"queue overflow"<<endl;
            return ;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void deque(){
        if(front==-1||front>back){
            cout<<"no elements in queue"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1||front>back){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        if(front==-1||front>back){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<q.peek()<<endl;
    q.deque();

    cout<<q.peek()<<endl;
    q.deque();

    cout<<q.peek()<<endl;
    q.deque();

    cout<<q.peek()<<endl;
    q.deque();

    cout<<q.empty();

    return 0;

}