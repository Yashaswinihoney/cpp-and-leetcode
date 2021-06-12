#include<iostream>
#include<map>
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

void SumV(Node* root, int hd, map<int,int> &m){
    if(root==NULL) return;
    SumV(root->left,hd-1,m);
    m[hd]+=root->val;
    SumV(root->right,hd+1,m);
}

void Sum(Node* root){
    map<int,int> m;
    SumV(root,0,m);
    for(auto i:m){
        cout<<i.second<<" ";
    }
}

void Inorder(Node* root){
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

int main(){
    Node* root=new Node(8);
    root->left=new Node(6);
    root->left->left=new Node(5);
    root->left->right=new Node(7);
    root->right=new Node(10);
    root->right->left=new Node(9);
    root->right->right=new Node(11);
    Inorder(root);
    cout<<endl;
    Sum(root);
    return 0;
}
