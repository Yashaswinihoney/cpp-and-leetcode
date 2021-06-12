#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;

    node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

void preorder(node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

//searching for a key
bool bsearch(node* root, int key){
    if(root==NULL) return false;
    if(root->val==key) return true;
    else if(key<root->val) return(bsearch(root->left,key));
    else if(key>root->val) return(bsearch(root->right,key));
    else return false;
}

//inserting a key
node* insert(node* root, int val){
    if(root==NULL){
        return new node(val);
    }
    else if(root->val<val){
        root->right=insert(root->right,val);
    }
    else if(root->val>val){
        root->left=insert(root->left,val);
    }
    return root;
}
int main(){
    /*node* root =new node(15);
    root->left=new node(5);
    root->left->left=new node(3);
    root->right=new node(20);
    root->right->left=new node(18);
    root->right->left->left=new node(16);
    root->right->right=new node(80);*/
    node* root=new node(10);
    root->left=new node(5);
    root->right=new node(15);
    root->right->left=new node(12);
    root->right->right=new node(18);
    //cout<<bsearch(root,5);
    //cout<<endl;
    //cout<<bsearch(root,8);
    preorder(root);
    cout<<endl;
    insert(root,20);
    preorder(root);
    return 0;
}