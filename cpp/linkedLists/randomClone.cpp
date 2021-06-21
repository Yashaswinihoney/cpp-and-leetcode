#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next, *random;

    Node(int val){
        data=val;
        next=random=NULL;
    }
};

void print(Node *start) 
{ 
    Node *ptr = start; 
    while (ptr) 
    { 
        cout << "Data = " << ptr->data << ", Random  = "<< ptr->random->data << endl; 
        ptr = ptr->next; 
    } 
}

Node* clone(Node* head){
    unordered_map<Node*,Node*> mp;

    //here we are pushing the data into the mp
    for(Node* curr=head;curr;curr=curr->next){
        mp[curr]=new Node(curr->data);
    }
    Node* head2;
    for(Node* curr=head;curr;curr=curr->next){
        //now we are linking the next and random 
        //pointers of the node to create
        //the exact same linked list
        Node* clone=mp[curr];
        clone->next=mp[curr->next];
        clone->random=mp[curr->random];
    }
    head2=mp[head];
    return head2;
}


int main() 
{ 
	Node* head = new Node(10); 
    head->next = new Node(5); 
    head->next->next = new Node(20); 
    head->next->next->next = new Node(15); 
    head->next->next->next->next = new Node(20); 
    
    head->random = head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next->next;
    
    cout << "Original list : \n"; 
    print(head); 
  
    cout << "\nCloned list : \n"; 
    Node *cloned_list = clone(head); 
    print(cloned_list); 
  
    return 0; 
} 