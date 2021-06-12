#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    public:
    Node *front, *rear;
};

void enQueue(Queue* q, int val){
    Node* temp= new Node(val);

    if(q->front==NULL){
        q->front=temp;
    }
    q->rear=temp;
    q->rear->next=q->front;
}

int deQueue(Queue *q){
    if(q->front==NULL){
        cout<<"queue underflow"<<endl;
        return -1;
    }
    int del;
    if(q->front==q->rear){
        del=q->front->data;
        delete(q->front);
        q->front=NULL;
        q->rear=NULL;
    }
    else{
        Node* temp=q->front;
        del=temp->data;
        q->front=q->front->next;
        delete(temp);
    }
    return del;
}

bool empty(Queue* q){
    if(q->front==NULL){
        return true;
    }
    return false;
}

void display(Queue* q){
    if(q->front==NULL){
        cout<<"queue is empty"<<endl;
    }
    else{
        Node* temp=q->front;
        while(temp->next != q->front){
            cout<<temp->data<<endl;
            temp=temp->next;
        }   
        cout<<temp->data<<endl; 
    }
}

int main()
{
    Queue* q = new Queue;
    q->front = q->rear = NULL;
  
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);
  
    display(q);
  
    cout<<"\nDeleted value =", deQueue(q);
    cout<<"\nDeleted value = ", deQueue(q);
  
    display(q);
  
    enQueue(q, 9);
    enQueue(q, 20);
    display(q);
  
    return 0;
}