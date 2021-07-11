#include<iostream>
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

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<endl;
}

//int ind=0;

Node* tree(int pre[], int &index, int s, int e, int n){
    if(index>=n) return NULL;
    if(s>e) return NULL;

    Node* root=new Node(pre[index++]);
    if(s==e) return root;

    //now we find out the first element thet is greater than root->val
    int i=0;
    for(i=s;i<=e;i++){
        if(pre[i]>pre[index]){
            break;
        }
    } 

    root->left=tree(pre,index,s,i-1,n);
    root->right=tree(pre,index,i,e,n);
    return root;
}

Node* construct(int pre[], int n){
    int ind=0;
    Node* root=tree(pre,ind,0,n-1,n);
    return root;
}

int main(){
    int n=7;
    /*Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(8);*/
    
    int preorder[]={4,2,1,3,7,6,8};
    Node* root=construct(preorder,n);
    postorder(root);
    return 0;
}