#include<iostream>
using namespace std;

//declaration and creation
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

//insert at front
void insertAtFront(node* &head, int val){
    node* n= new node(val);
    n->next=head;
    head=n;
}

//insert after a specified value
void insertAfter(node* &prev_node, int val){
    if(prev_node==NULL){
        cout<<"previous node cannot be null\n";
        return;
    }
    node* n=new node(val);
    n->next=prev_node->next;
    prev_node->next=n;
    return;
}

//insert at end
void insertAtTail(node* &head, int val){
    
    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

//searching in a linked list
bool search(node* head,int key){
    node* temp=head;

    while (temp!=NULL)
    {
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
    
}

//print the linked list
void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {   
        cout<<(temp->data)<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

//deleting first node
void deletefirst(node* &head){
    node* temp=head;
    head=head->next;
    delete temp;
}

//deleting a node
void deletion(node* &head, int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deletefirst(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete= temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

//reverse a ll using iterative method, three pointers
node* reverse(node* &head){
    node* prev;
    node* curr;
    node* next;
    prev=NULL;
    curr=head;
    while (curr!=NULL)
    {   
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;  
}

//reverse a ll using recurrsion
node* reverseRec(node* &head){

    //for an empty ll or a single node
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newHead= reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

//reversing k nodes;
node* reversek(node* &head, int k){
    node* prev=NULL;
    node* curr=head;
    node* next;
    int count=0;

    while(curr!=NULL &&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL){
        head->next=reversek(next,k);
    }
    return prev;
}

//making a cycle
void makeCycle(node* &head, int pos){
    node* temp=head;
    node* startHead;
    int count =1;
    while (temp->next!=NULL)
    {
        if(count==pos){
            startHead=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startHead;
    return;
}

//detect a cycle
bool detectCycle(node* &head){
    node* slow= head;
    node* fast= head;
    while (fast!=NULL &&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false; 
}

//deleting a cycle
void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while (fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
    
}

//method 2 and better
/*void removeLoop(Node* head)
    {
        if(!head) return;
        
        Node *slow = head;
        Node *fast = head->next;
        
        while(slow!=fast){
            if(!fast || !fast->next){
                return;
            }
            else{
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        int size = 1;
        fast = fast->next;
        
        while( fast != slow )
        {
            size++;
            fast = fast->next;
        }
        
        slow = fast = head;
        for(int i=0; i<size-1; i++)
            fast = fast->next;
            
        while(fast->next!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = NULL;
        // code here
        // just remove the loop without losing any nodes
    }*/
//finding the length of the ll
int length(node* head){
    int l=0;
    node* temp=head;
    while (temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

//appending k elements from the last to the starting of the linked list
node* kappend(node* head, int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int l=length(head);
    int count =1;
    k=k%l;
    while (tail->next!=NULL)
    {
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}

//intersecting two linked lists
void intersect(node* &head1, node* &head2, int pos){
    node* temp1=head1;
    int i=1;
    while (i<pos)
    {
        temp1=temp1->next;
        i++;
    }
    
    node* temp2=head2;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

//finding the intersection of two ll
int intersection(node* &head1, node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    node* ptr1; //pointing to the ll with greater length
    node* ptr2; //pointing to the ll with shorter length

    int d=0;

    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while (d)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    
    while (ptr1!=NULL&& ptr2!=NULL)
    {   
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
    return -1;
}

//merging two sorted ll
node* merge(node* &head1, node* &head2){
    node* p1=head1;
    node* p2= head2;
    node* dummyNode=new node(-1);;
    node* p3=dummyNode;

    while (p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
    }

    while (p1!=NULL)
    {
        p3->next=p1;
        p3=p3->next;
        p1=p1->next;
    }
    while (p2!=NULL)
    {
        p3->next=p2;
        p3=p3->next;
        p2=p2->next;
    }
        
    return dummyNode->next; 
}

//merge recursive
node* meregeRec( node* &head1, node* &head2){
    if(head1==NULL){
        return head2;
    }

    if(head2==NULL){
        return head1;
    }
    
    node* res;
    if(head1->data<head2->data){
        res=head1;
        res->next=meregeRec(head1->next,head2);
    }
    else{
        res=head2;
        res->next=meregeRec(head1,head2->next);
    }
    return res;
}

//adding elements at even positions after those at odds
void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    if(odd->next!=NULL){
        even->next=NULL;
    }

    odd->next=evenStart;
}

int main(){
    //node* head1=NULL;
    //insertAtTail(head1,1);
    //insertAtTail(head1,2);
    //insertAtTail(head1,3);
    //insertAtTail(head1,4);
    //insertAtTail(head1,5);
    //insertAtTail(head1,6);
    //insertAtFront(head,10);
    //insertAtFront(head,7);
    //insertAtTail(head1,1);
    //insertAtTail(head1,4);
    //insertAtTail(head1,5);
    //insertAtTail(head1,7);
    //print(head1);
    //cout<<(search(head,3));
    //deletion(head,3);
    //insertAfter(head->next,8);
    //node* newHead= reverseRec(head);
    //print(newHead);
    //node* newHead= reversek(head,2);
    //print(newHead);
    //makeCycle(head,3);
    //cout<<detectCycle(head)<<endl;
    //removeCycle(head);
    //cout<<detectCycle(head)<<endl;
    //print(head);
    //node* newHead=kappend(head,5);
    //print(newHead);

    //node* head2=NULL;
    //insertAtTail(head2, 5);
    //insertAtTail(head2,10);
    //insertAtTail(head2,15);
    //insertAtTail(head2,20);
    //print(head2);
    //intersect(head1,head2,4);
    //cout<<(intersection(head1,head2));
    //insertAtTail(head2,2);
    //insertAtTail(head2,3);
    //insertAtTail(head2,6);
    //print(head2);
    //node* head3=merge(head1,head2);
    //print(head3);

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);

    display(head);

    evenAfterOdd(head);
    display(head);
    return 0;
}
