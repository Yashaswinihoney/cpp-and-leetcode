#include<iostream>
#include<stack>
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

void inOrder(Node* root){
    if(root){
        stack <Node *> st;
        //st.push(root);
        st.push(root);
        while(!st.empty()){
            Node* curr=st.top();
            cout<<curr->val<<" ";
            st.pop();
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
        }
    }
}

int main(){
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    inOrder(root);
    return 0;
}