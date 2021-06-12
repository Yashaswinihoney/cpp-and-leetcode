#include<iostream>
using namespace std;

//creation
class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

//adding an element in front 
void insertAtHead(node* &head,int val){

    node* n= new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
    return;
}

//adding an element at the end
void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);
    node* temp=head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    return;
}

//deleting from the start
void deleteAtHead(node* &head,int pos){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete(todelete);
    return;
}

//deleting
void deletion(node* &head,int pos){
    node* temp= head;

    if(pos==1){
        deleteAtHead(head,pos);
        return;
    }

    int count=1;

    while (temp!=NULL&&count!=pos)
    {
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;

    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

    delete(temp);
    return;
}

//printing
void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    //display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,1);
    display(head);
    return 0;
}