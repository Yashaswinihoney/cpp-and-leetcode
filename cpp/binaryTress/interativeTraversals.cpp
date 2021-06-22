#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int val;
    Node* left, *right;

    Node(int x){
        val=x;
        left=right=NULL;
    }
};

void inorder(Node* root){
    
    stack<Node*> s;
    Node* curr=root;
    while (curr||!s.empty())
    {
        while (curr)
        { 
            s.push(curr);
            curr=curr->left;
        }

        curr=s.top();
        s.pop();
        cout<<curr->val<<" ";
        curr=curr->right;
    }
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    inorder(root);
    return 0;
}