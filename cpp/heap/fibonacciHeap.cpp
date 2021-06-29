#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    Node *left, *right, *child, *parent;

    Node(int x){
        key=x;
        child=NULL;
        parent=NULL;
    } 
};

Node* minimum= NULL;
int no_of_nodes=0;

void insertion(int val){
    Node* new_node=new Node(val);
    new_node->left=new_node;
    new_node->right=new_node;
    if(minimum!=NULL){
        minimum->left->right=new_node;
        new_node->right=minimum;
        new_node->left=minimum->left;
        minimum->left=new_node;
        if(minimum->key>new_node->key){
            minimum=new_node;
        }
    }
    else{
        minimum=new_node;
    }
}

void display(Node* minimum){
    if(minimum==NULL){
        return;
    }
    else{
        Node* ptr=minimum;
        do{
            cout<<ptr->key;
            ptr=ptr->right;
            if(ptr!=minimum){
                cout<<"-->";
            }
        }while (ptr!=minimum&&ptr->right!=NULL);
    }
}

int find_min(Node* minimum){
    return minimum->key;
}

int main()
{
 
    no_of_nodes = 7;
    insertion(4);
    insertion(3);
    insertion(7);
    insertion(5);
    insertion(2);
    insertion(1);
    insertion(10);
 
    display(minimum);
 
    cout<<find_min(minimum)<<endl;
 
    return 0;
}