#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
class Node{
    public:
    char val;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int v, Node* l=NULL, Node* r=NULL){
        val=c;
        freq=v;
        left=l;
        right=r;
    }
};

struct compare
{
    bool operator()(Node* a,Node* b){
        return (a->freq<b->freq);
    }
};

void printCode(Node* root,string str){
    if(root==NULL) return;
    if(root->val!='$'){
        cout<<root->val<<" "<<str<<endl;
        return;
    }
    printCode(root->left, str+"0");
    printCode(root->right, str+"1");
}

void printHCodes(vector<char> v, vector<int> f, int n){
    priority_queue<Node*,vector<Node*>,compare> pq;
    for(int i=0;i<n;i++){
        pq.push(new Node(v[i],f[i]));
    }
    while(pq.size()>1){
        Node* l=pq.top();
        pq.pop();
        Node* r=pq.top();
        pq.pop();
        Node* node=new Node('$',l->freq+r->freq,l,r);
        pq.push(node);
    }
    printCode(pq.top(),"");
}

int main(){
    vector<char> v;
    v.push_back('a');
    v.push_back('d');
    v.push_back('e');
    v.push_back('f');
    //('a','d','e','f');
    vector<int> f;
    f.push_back(30);
    f.push_back(40);
    f.push_back(80);
    f.push_back(60);
    //(30, 40, 80, 60);
    int size=v.size();
    printHCodes(v,f,size);
    return 0;
}