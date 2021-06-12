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

//simple and efficient method 1
bool check(Node* root, int min,int max){
    if(root==NULL) return true;
    return(root->val<max&&root->val>min&&check(root->left,min,root->val)&&check(root->right,root->val,max));
}

//method 2
bool Check(Node* root){
    int prev=-100000;
    if(root==NULL) return true;
    if(Check(root->left)==false) return false;
    if(root->val<=prev) return false;
    prev=root->val;
    return(Check(root->right));
}

int main(){
    Node* root=new Node(9);
    root->left=new Node(7);
    root->left->left=new Node(6);
    root->left->right=new Node(8);
    root->right=new Node(14);
    root->right->left=new Node(11);
    root->right->right=new Node(18);
    cout<<check(root,0,100)<<" ";
    return 0;
}