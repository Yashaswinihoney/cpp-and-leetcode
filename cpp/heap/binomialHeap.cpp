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

//merging the binomial tree
//only those binomial trees can be merged whose degrees are same
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
list<Node*> adjust(list<Node*> _heap)
{
    if (_heap.size() <= 1)
        return _heap;
    list<Node*> new_heap;

    //for maintaing the previous, current and next
    list<Node*>::iterator it1,it2,it3;
    it1 = it2 = it3 = _heap.begin();
  
    if (_heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = _heap.end();
    }
    else
    {
        it2++;
        it3=it2;
        it3++;
    }
    while (it1 != _heap.end())
    {
        // if only one element remains to be processed
        if (it2 == _heap.end())
            it1++;
  
        // If D(it1) < D(it2) i.e. merging of Binomial
        // Tree pointed by it1 & it2 is not possible
        // then move next in heap
        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if(it3!=_heap.end())
                it3++;
        }
  
        // if D(it1),D(it2) & D(it3) are same i.e.
        // degree of three consecutive Binomial Tree are same
        // in heap
        else if (it3!=_heap.end() &&
                (*it1)->degree == (*it2)->degree &&
                (*it1)->degree == (*it3)->degree)
        {
            it1++;
            it2++;
            it3++;
        }
  
        // if degree of two Binomial Tree are same in heap
        else if ((*it1)->degree == (*it2)->degree)
        {
            Node *temp;
            *it1 = mergeBinTree(*it1,*it2);
            it2 = _heap.erase(it2);
            if(it3 != _heap.end())
                it3++;
        }
    }
    return _heap;
}
  
// inserting a Binomial Tree into binomial heap
list<Node*> insertATreeInHeap(list<Node*> _heap,
                              Node *tree)
{
    // creating a new heap i.e temp
    list<Node*> temp;
  
    // inserting Binomial Tree into heap
    temp.push_back(tree);
  
    // perform union operation to finally insert
    // Binomial Tree in original heap
    temp = unionBinHeap(_heap,temp);
  
    return adjust(temp);
}
  
// removing minimum key element from binomial heap
// this function take Binomial Tree as input and return
// binomial heap after
// removing head of that tree i.e. minimum element
list<Node*> removeMinFromTreeReturnBHeap(Node *tree)
{
    list<Node*> heap;
    Node *temp = tree->child;
    Node *lo;
  
    // making a binomial heap from Binomial Tree
    while (temp)
    {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;
        heap.push_front(lo);
    }
    return heap;
}
  
// inserting a key into the binomial heap
list<Node*> insert(list<Node*> _head, int key)
{
    Node *temp = new Node(key);
    return insertATreeInHeap(_head,temp);
}
  
// return pointer of minimum value Node
// present in the binomial heap
Node* getMin(list<Node*> _heap)
{
    list<Node*>::iterator it = _heap.begin();
    Node *temp = *it;
    while (it != _heap.end())
    {
        if ((*it)->data < temp->data)
            temp = *it;
        it++;
    }
    return temp;
}
  
list<Node*> extractMin(list<Node*> _heap)
{
    list<Node*> new_heap,lo;
    Node *temp;
  
    // temp contains the pointer of minimum value
    // element in heap
    temp = getMin(_heap);
    list<Node*>::iterator it;
    it = _heap.begin();
    while (it != _heap.end())
    {
        if (*it != temp)
        {
            // inserting all Binomial Tree into new
            // binomial heap except the Binomial Tree
            // contains minimum element
            new_heap.push_back(*it);
        }
        it++;
    }
    lo = removeMinFromTreeReturnBHeap(temp);
    new_heap = unionBinHeap(new_heap,lo);
    new_heap = adjust(new_heap);
    return new_heap;
}
  
// print function for Binomial Tree
void printTree(Node *h)
{
    while (h)
    {
        cout << h->data << " ";
        printTree(h->child);
        h = h->sibling;
    }
}
  
// print function for binomial heap
void printHeap(list<Node*> _heap)
{
    list<Node*> ::iterator it;
    it = _heap.begin();
    while (it != _heap.end())
    {
        printTree(*it);
        it++;
    }
}

int main()
{
    int ch,key;
    list<Node*> _heap;
  
    // Insert data in the heap
    _heap = insert(_heap,10);
    _heap = insert(_heap,20);
    _heap = insert(_heap,30);
  
    cout << "Heap elements after insertion:\n";
    printHeap(_heap);
  
    Node *temp = getMin(_heap);
    cout << "\nMinimum element of heap "
         << temp->data << "\n";
  
    // Delete minimum element of heap
    _heap = extractMin(_heap);
    cout << "Heap after deletion of minimum element\n";
    printHeap(_heap);
  
    return 0;
}