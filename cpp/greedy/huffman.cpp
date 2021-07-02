#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
class Node{
    public:
    char val;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int v){
        val=c;
        freq=v;
    }
};

void printCode(Node* root,string str=""){
    if(root==NULL) return;
    if(root->val!='$'){
        cout<<root->val<<" "<<str;
        return;
    }
    printCode(root->left, str+"0");
    printCode(root->right, str+"1");
}
int main(){

}