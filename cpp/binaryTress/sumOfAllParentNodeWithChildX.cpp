#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};

int sumOfParentOfXUtil(Node* root, int x){
    if(root==NULL) return 0;
    if(root->left&&root->right)
        if(root->left->data==x||root->right->data==x){
            return root->data+sumOfParentOfXUtil(root->left,x)+sumOfParentOfXUtil(root->right,x);
        }
    
    else if (root->left)
    {
        if(root->left->data==x){
            root->data+sumOfParentOfXUtil(root->left,x)+sumOfParentOfXUtil(root->right,x);
        }
    }

    else if (root->right)
    {
        if(root->right->data==x){
            root->data+sumOfParentOfXUtil(root->left,x)+sumOfParentOfXUtil(root->right,x);
        }
    }
    
    return 0;
}

int main(){
    Node *root =new Node(4);         
    root->left =new Node(2);         
    root->right = new Node(5); 
    root->left->left = new Node(7);     /*     / \ / \     */
    root->left->right = new Node(2);    /*    7  2 2  3    */
    root->right->left = new Node(2);
    root->right->right = new Node(3);
     
    int x = 2;
     
    cout << "Sum = "
         << sumOfParentOfXUtil(root, x);
          
    return 0;   

}