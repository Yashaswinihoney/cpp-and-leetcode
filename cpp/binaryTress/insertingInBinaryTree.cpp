#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

/*void insert(node* root, int val){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* num=q.front();
        q.pop();
        if(root->left==NULL){
            root->left=num;
            break;
        }
        else{
            q.push(root->left);
        }

        if(root->right==NULL){
            root->right=num;
        }
        else{
            q.push(root->right);
        }

    }
}*/

void insert(node* temp, int key) 
{ 
    queue<node*> q; 
    q.push(temp); 

    // Do level order traversal until we find 
    // an empty place. 
    while (!q.empty()) { 
        struct node* temp = q.front(); 
        q.pop(); 

        if (!temp->left) { 
            temp->left = new node(key); 
            break; 
        } else
            q.push(temp->left); 

        if (!temp->right) { 
            temp->right = new node(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
} 

//size( number of nodes in a binary tree)
int size(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+size(root->left)+size(root->right);
}

//max of the tree
int maximum(node* root){
    if(root==NULL){
        return -1;
    }
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}

//leftview
void leftview(node* root){
    if(root==NULL){
        return;
    }
    queue< node* > q;
    q.push(root);
    while (!q.empty())
    {
        int count =q.size();
        for(int i=0;i<count;i++){
            node* curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<endl;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}

//right view
void rightview(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            node* curr=q.front();
            q.pop();

            if(i==size-1){
                cout<<curr->data<<endl;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}

void printLevel(node* root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//child sum property
bool isSum(node* root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL&&root->right==NULL){
        return true;
    }
    int sum=0;
    if(root->left){
        sum+=root->left->data;
    }
    if(root->right){
        sum+=root->right->data;
    }
    return(root->data==sum&&isSum(root->left)&&isSum(root->right));
}

//check if a tree is balanced
bool isBalanced(node* root){
    if(root==NULL) return 0;
    int lh=isBalanced(root->left);
    if(lh==-1) return -1;
    int rh=isBalanced(root->right);
    if(rh==-1) return -1;
    //if the absolute difference of lh and rh is greater than 1 then return -1
    if(!((lh-rh==0)||(lh-rh==-1)||(lh-rh==1))) return -1;
    return max(lh,rh)+1;
}

//finding the height of the tree
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=height(root->left);
    int rHeight=height(root->right);
    return max(lHeight,rHeight)+1;
}

//calculating diametere of the root method 1 O(n^2)
int diameter(node* root){
    if(root==NULL) return 0;
    int d1=1 +height(root->left)+height(root->right);
    int d2=diameter(root->left);
    int d3=diameter(root->right);
    return max(d1,max(d2,d3));
}

/* method 2
int res=0;
int height(Node *root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    res=max(res,1+lh+rh);
    
    return 1+max(lh,rh);
}*/

//max width of any level
int maxwidth(node* root){
    if(root==NULL) return 0;
    queue<node*> q;
    q.push(root);
    int res=0;
    while (!q.empty())
    {
        int s=q.size();
        res=max(res,s);
        for (int i = 0; i < s; i++)
        {
            node* curr=q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }    
    }
    return res;
}

// converting a binary tree to doubly linked list
node* toDLL(node* root){
    node* prev=NULL;

    if(root==NULL) return root;
    node* head=toDLL(root->left);
    if(prev==NULL){
        head=root;
    }
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    toDLL(root->right);
    return head;
}

//sprial tree traversal
/*void printSpiral(node* root){
    if (root==NULL)
    {
        return; 
    }
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);
    while((!s1.empty())||(!s2.empty())){
        while (!s1.empty())
        {
            node* temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right){
                s2.push(temp->right);
            }
            if(temp->left){
                s2.push(temp->left);
            }
        }
        while (!s2.empty())
        {
            node* temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->left);
            }
        }    
    }    
}*/
void printSpiral(node *root){
    if (root == NULL) 
        return;  

    stack<node*> s1;  
    stack<node*> s2;  
  
    s1.push(root); 
  
    while (!s1.empty() || !s2.empty()) { 
        while (!s1.empty()) { 
            node* temp = s1.top(); 
            s1.pop(); 
            cout << temp->data << " "; 
  
            if (temp->right) 
                s2.push(temp->right); 
            if (temp->left) 
                s2.push(temp->left); 
        } 
        
        while (!s2.empty()) { 
            node* temp = s2.top(); 
            s2.pop(); 
            cout << temp->data << " "; 
  
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right); 
        } 
    } 
}  

//delteion of the deeepest rightmost node
void deletionDeep(node* root, node* nDeep){
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp->right){
            if(temp->right==nDeep){
                temp->right=NULL;
                delete(nDeep);
                return;
            }
            else{
                q.push(temp->right);
            }
        }
        if(temp->left){
            if(temp->left==nDeep){
                temp->left=NULL;
                delete(nDeep);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
    }
    
}

//deletion
void deletetion(node* root, int key){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    node* temp;
    node* keynode=NULL;
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==key)
            keynode=temp;
        
        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
    int x=temp->data;
    deletionDeep(root,temp);
    keynode->data=x;
}

/*void printLevel(node* root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    
}*/

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    //cout<<root->data;
    //preorder(root);
    //printLevel(root);
    //cout<<endl;
    //insert(root, 8);
    //printLevel(root);
    //preorder(root);
    //cout<<size(root);
    //cout<<maximum(root);
    //leftview(root);
    //cout<<endl;
    //rightview(root);
    //cout<<isBalanced(root);
    //cout<<maxwidth(root);
    //cout<<diameter(root);
    //printSpiral(root);
    //preorder(root);
    //cout<<endl;
    //deletetion(root,4);
    //preorder(root);
    printSpiral(root);
    return 0;
}