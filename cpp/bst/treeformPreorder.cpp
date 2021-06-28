#include<iostream>
#include<vector>
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

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//method 1
Node* construct(int pre[], int* preIndex, int low, int high, int size){
    if (*preIndex >= size||low>high)
    {
        return NULL;
    }
    Node* root=new Node(pre[*preIndex]);
    *preIndex=*preIndex+1;

    if(low==high) return root;

    int i;
    for(i=low;i<=high;i++){
        if(pre[i]>root->data)
            break;
    }
    root->left=construct(pre,preIndex,*preIndex,i-1,size);
    root->right=construct(pre, preIndex,i,high, size);
    return root;
}

//method 2
Node* construct2(int pre[], int* preIndex, int key, int min, int max, int size){
    if(*preIndex>=size){
        return NULL;
    }

    Node* root=NULL;

    if(key>min&&key<max){
        root=new Node(key);
        *preIndex=*preIndex+1;

        if(*preIndex<size){
            root->left=construct2(pre,preIndex,pre[*preIndex],min,key,size);
        }
        if(*preIndex<size){
            root->right=construct2(pre,preIndex,pre[*preIndex],key,max,size);
        }
    }
    return root;
}

Node* tree(int pre[], int size){
    int preIndex=0;
    
    //method 1
    return construct(pre,&preIndex,0, size-1,size);

    //method 2, by setting the range of a node
    //int place if -100 and +100 use INT_MIN and INT_MAX
    //return construct2(pre,&preIndex, pre[0], -100, +100,size);
}

int main(){
   int pre[]={10,5,1,7,40,50};
   int size=sizeof(pre)/sizeof(pre[0]);

   Node* root= tree(pre,size);
   inorder(root);
   return 0; 
}