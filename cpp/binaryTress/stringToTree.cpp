#include <iostream>
#include <stack>
#include <string>
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

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int findIndex(string str, int l, int r){
    if(l>r) return -1;

    stack<char> s;
    for(int i=l;i<=r;i++){
        if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            if(s.top()=='('){
                s.pop();

                if(s.empty()){
                    return i;
                }
        }
    }

    return -1;
}

Node* toTree(string str, int s, int e);

Node* toTree(string str, int s, int e){

    if(s>e){
        return NULL;
    }

    Node *root=new Node(str[s]-'0');

    int index=-1;

    if(s+1<=e&&str[s+1]=='('){
        index=findIndex(str,s+1,e);
    }

    if(index!=-1){
        root->left=toTree(str,s+2,index-1);

        root->right=toTree(str,index+2,e-1);
    }

    return root;
}

int main(){
    string str="4(2(3(1))(6(5))(5))";
    Node* root=toTree(str,0,str.length()-1);
    preorder(root);
    return 0;
}