#include <iostream>
using namespace std;

class Node{
    public:
    int key; 
    Node *left; 
    Node *right; 
    Node(int k){
        key=k;
        left=right=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->key<<" ";
        curr=curr->right;
    }cout<<endl;
}

Node* pre=NULL;
Node* BTToDLL(Node* root){
    if(root==NULL) return root;

    Node* head=BTToDLL(root->left);
    if(pre==NULL){
        head=root;
    }
    else{
        root->left=pre;
        pre->right=root;
    }
    pre=root;
    BTToDLL(root->right);

    return head;
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(20);
	root->right->left=new Node(30);
	root->right->right=new Node(35);
	
	Node *head=BTToDLL(root);
	printlist(head);
}