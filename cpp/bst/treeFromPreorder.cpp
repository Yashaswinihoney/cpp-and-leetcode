#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<endl;
}

int ind=0;

Node* construct(int pre[], int n){
    if(ind>=n) return NULL;
    Node* root;
    
    root =new Node(pre[ind++]);
    if(pre[ind++]<root->val){
        root->left=construct(pre,n);
    }
    else{
        root->right=construct(pre,n);
    }
    return root;
}

int main(){
    int n=7;
    /*Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(8);*/
    
    int preorder[]={4,2,1,3,7,6,8};
    Node* root=construct(preorder,n);
    postorder(root);
    return 0;
}