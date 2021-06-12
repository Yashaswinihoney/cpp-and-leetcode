#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=right=NULL;
    }
};
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int floor(node* root, int x){
    if(root==NULL) return -1;
    int res;
    while (root!=NULL)
    {
        if(root->data==x){
            return x;
        }
        else if(root->data>x){
            root=root->left;
        }
        else{
            res=root->data;
            root=root->right;
        }
    }
    return res;
}
int ceiling(node* root, int x){
    if(root==NULL) return -1;
    int res=0;
    while (root!=NULL)
    {
        if(root->data==x){
            return x;
        }
        else if(root->data>x){
            res=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return res;
}
int main(){
    node* root=new node(10);
    root->left=new node(5);
    root->right=new node(15);
    root->right->left=new node(12);
    root->right->right=new node(30);
    preorder(root);
    cout<<endl;
    //cout<<floor(root,10);
    cout<<ceiling(root,31);
    return 0;
}