#include<iostream>
using namespace std;
class StackNode{
    public:
    int data;
    StackNode* next;
    StackNode(int val){
        data=val;
        next=NULL;
    }
};

int isEmpty(StackNode* root){
    return !root;
}

void push(StackNode* &root, int val){
    StackNode* temp=new StackNode(val);
    temp->next=root;
    root=temp;
    cout<<"pushed into the stack"<<endl;
}

void pop(StackNode* &root){
    StackNode* temp=root;
    root=root->next;
    cout<<temp->data;
    delete(temp);
    return;
}

int top(StackNode* root){
    return root->data;
}

int main(){
    StackNode* stack=NULL;
    push(stack,1);
    push(stack,2);
    push(stack,3);
    cout<< (top(stack));
    return 0;
}