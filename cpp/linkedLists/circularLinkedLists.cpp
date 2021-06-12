#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    
    if(head==NULL){
        n->next=n;
        head=n;
    }
    node* temp=head;

    do
    {
        temp=temp->next;
    } while (temp->next!=head);
    temp->next=n;
    n->next=head;
    head=n;
    return;
}

void inserAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);

    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    return;
}

void sortedInsert(node* &head, int val){
    node* n=new node(val);
    node* temp=head;

    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    else if (temp->data>=n->data)
    {
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;
        head=n;
    }
    else{
        while (temp->next!=head){
            if((temp->data)<val&&(temp->next->data)>val){
                n->next=temp->next;
                temp->next=n;
                return;
            }
            temp=temp->next;
        }
    
    }

}

void deleteAtHead(node* &head){
    node* toDelete= head;
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    delete(toDelete);
    return;

}

void deletion(node* &head, int pos){

    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while (count!=pos-1)
    {
        temp=temp->next;
        count++;
    }

    node* toDelete= temp->next;
    temp->next=temp->next->next;
    delete(toDelete);
    
}

void display(node* head){
    node* temp=head;
    do
    {
        cout<<(temp->data)<<endl;
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
    return;
}

int main(){
    node* head=NULL;
    inserAtTail(head,1);
    inserAtTail(head,2);
    inserAtTail(head,3);
    inserAtTail(head,4);
    inserAtTail(head,8);
    display(head);
    //deletion(head,1);
    sortedInsert(head,0);
    sortedInsert(head,6);
    sortedInsert(head,9);
    display(head);
    return 0;
}