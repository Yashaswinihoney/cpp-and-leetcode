#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int arr[], int start, int end, int val){
    for(start;start<=end;start++){
        if(arr[start]==val){
            return start;
        }
    }
}

void printInorder(Node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<endl;
    printInorder(root->right);
}

//using preorder and inorder
Node* buildTree(int inorder[], int preorder[], int start, int end){
    if(start>end)
        return NULL;
    
    static int index=0;
    int curr=preorder[index++];
    Node* root=new Node(curr);
    if(start==end)
        return root;
    
    int pos=search(preorder,start, end,curr);
    root->left=buildTree(inorder, preorder, start, pos-1);
    root->right=buildTree(inorder, preorder, pos+1,end);
    return root;
}

//using inorder and postorder
Node* build(int inorder[], int postorder[], int start,int end){
    if(start>end){
        return NULL;
    }
    static int index=sizeof(postorder)/sizeof(postorder[0]) -1;
    int val=postorder[index];
    index--;
    Node* curr=new Node(val);
    if(start==end) return curr;
    int pos=search(inorder,start,end,val);
    curr->right=build(inorder,postorder,pos+1,end);
    curr->left=build(inorder,postorder,start,pos-1);
    return curr;
}

//print level line by line
void printlevelline(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int count=q.size();
        for(int i=0;i<count;i++){
            Node* curr=q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout<<endl;
    }
    
}

int main(){
    //int preorder[]={1,2,4,5,3,6};
    //int postorder[]={4,2,5,3,1};
    //int inorder[]={4,2,1,5,3};
    //int inorder[]={4,2,5,1,6,3};
    //Node* root=buildTree(inorder,preorder,0,4);
    //Node* root=build(inorder,postorder,0,4);
    //printInorder(root);
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    printlevelline(root);
    return 0;
}