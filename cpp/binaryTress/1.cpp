#include<iostream>
using namespace std;

// node declaration and initialisation
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//preorder traversal
void preorder(Node* root){
    if (root==NULL)
    {
        return;
    }
    
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

//inorder traversal
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

//postorder traversal
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}


int main(){

    //int preorder[]={1,2,4,3,5};
    //int inorder[]={4,2,1,5,3};
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);
    //preorder(root);
    inorder(root);
    //postorder(root);
    
    return 0;
}