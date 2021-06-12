//method 1 by finding the height and the printing the elements at different distances including 1 to n
//complexity of  this method will be very high
//heince inefficient

//method 2 using queues
#include<iostream>
#include<queue>
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

void printLevel(Node* root){
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
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
    printLevel(root);
    return 0;
}