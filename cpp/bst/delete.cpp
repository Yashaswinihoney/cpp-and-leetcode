#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=right=NULL;
    }
};
void preorder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

node* successor(node* curr){
    curr=curr->right;
    while(curr!=NULL&&curr->left!=NULL)
        curr=curr->left;
    return curr;
}
node* deletenode(node* root, int x){
    if(root==NULL) 
        return root;
    if(root->data>x){
        root->left=deletenode(root->left,x);
    }
    else if(root->data<x){
        root->right=deletenode(root->right,x);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            node* succ=successor(root);
            root->data=succ->data;
            root->right=deletenode(root->right,succ->data);
        }
        return root;
    }
    return root;
}
int main(){
    node* root=new node(55);
    root->left=new node(30);
    root->left->left=new node(10);
    root->left->right=new node(40);
    root->right=new node(70);
    root->right->left=new node(60);
    root->right->left->left=new node(57);
    root->right->right=new node(80);
    preorder(root);
    cout<<endl;
    deletenode(root,60);
    preorder(root);
    return 0;
}
/*
#include <iostream>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

Node *getSuccessor(Node *curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}

Node *delNode(Node *root, int x){
    if(root==NULL)
        return root;
    if(root->key>x)
        root->left=delNode(root->left,x);
    else if(root->key<x)
        root->right=delNode(root->right,x);
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
} 

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
} 
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(12);
	root->right->right=new Node(18);
    inorder(root);
    cout<<endl;
	int x=15;
	
	root=delNode(root,x);
	inorder(root);
}*/