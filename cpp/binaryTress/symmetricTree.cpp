#include<iostream>
#include<queue>
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

//to check if the tree is symmetric using recurrsion
//base function
bool sym(Node* l, Node* r){
    if(l==NULL&&r==NULL) return true;

    if((l!=NULL&&r==NULL)||(l==NULL&&r!=NULL)) return false;

    if(l&&r&&l->val==r->val)
        return(sym(l->left,r->right)&&sym(l->right,r->left));
    return false;
}

//wrapper function
bool IsSymmetric(Node* root){
    return sym(root,root);
}

//to check if the tree is symmetric using iterative method
bool Symmetric(Node* root){
    if(root==NULL) return true;

    queue<Node*> q;
    q.push(root);
    q.push(root);

    while (!q.empty())
    {
        Node* l=q.front();
        q.pop();
        Node* r=q.front();
        q.pop();

        if(l->left&&r->right){
            q.push(l->left);
            q.push(r->right);
        }
        else if(l->left||r->right) return false;

        if(l->right&&r->left){
            q.push(l->right);
            q.push(r->left);
        }
        else if(l->right||r->left) return false;
    }
    return true;
}