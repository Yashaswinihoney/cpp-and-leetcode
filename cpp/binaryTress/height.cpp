#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorderDisplay(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    preorderDisplay(root->left);
    preorderDisplay(root->right);
}

//finding the height of the tree
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=height(root->left);
    int rHeight=height(root->right);
    return max(lHeight,rHeight)+1;
}

//printing at a distance
void printAtdist(Node* root, int k){
    if(root==NULL)
        return;
    if(k==0) cout<<root->data<<endl;
    else    
        printAtdist(root->left,k-1);
        printAtdist(root->right,k-1);
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    preorderDisplay(root);
    cout<<height(root);
    printAtdist(root,2);
    return 0;
}
