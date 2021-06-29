#include<iostream>
#include<list>
using namespace std;

class Node{
    public:
    int data, degree;
    Node *child, *sibling, *parent;

    Node(int key){
        data=key;
        degree=0;
        child=sibling=parent=NULL;
    }
};

//mergeing the binomial heap
Node* mergeBinTree(Node* b1, Node* b2){
    //making sure that b1 is smaller
    if(b1->data>b2->data){
        swap(b1,b2);
    }

    b2->parent=b1;
    b2->sibling=b1->child;
    b1->child=b2;
    b1->degree++;

    return b1;
}

//union of binomial heap
list<Node*> unionBinHeap(list<Node*> l1, list<Node*> l2){
    list<Node*> _new;
    list<Node*>:: iterator it=l1.begin();
    list<Node*>:: iterator ot=l2.begin();

    while(it!=l1.end()&&ot!=l2.end()){
        if((*it)->degree <= (*ot)->degree)
        {
            _new.push_back(*it);
            it++;
        }
        
        else
        {
            _new.push_back(*ot);
            ot++;
        }
    }
    while (it != l1.end())
    {
        _new.push_back(*it);
        it++;
    }
  
    while (ot!=l2.end())
    {
        _new.push_back(*ot);
        ot++;
    }
    return _new;
}


//to adjust the heap so that the eap is in increaing order of the degrees and no
//two trees have the same degree
