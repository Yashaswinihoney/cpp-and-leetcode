#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val=x;
        left=right=NULL;
    }
};
void Inorder(Node* root){
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

Node *p=NULL, *first=NULL, *second=NULL;
void fixBST(Node* root){

    if(root==NULL) return;
    fixBST(root->left);
    if(p!=NULL&&root->val<=p->val){
        if(first==NULL) first=p;
        second=root;
    }
    p=root;
    /*int t=first->val;
    first->val=second->val;
    second->val=t;*/
    fixBST(root->right);
    //swap(first->val,second->val);
}
int main(){
    Node* root=new Node(18);
    root->left=new Node(60);
    root->left->left=new Node(4);
    root->right=new Node(70);
    root->right->left=new Node(8);
    root->right->right=new Node(80);
    Inorder(root);
    cout<<endl;
    fixBST(root);
    int t=first->val;
    first->val=second->val;
    second->val=t;
    Inorder(root);
    return 0;
}