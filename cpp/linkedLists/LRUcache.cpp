#include<iostream>
#include<unordered_map>
using namespace std;

class Node
{
    public:
    int key,val;
    Node* pre, *next;
    Node(int k, int v);
};

Node::Node(int k, int v)
{
    key=k;
    val=v;
    pre=NULL;
    next=NULL;
}

class LRUCache
{
    public: 
    unordered_map<int,Node*> map;
    int capacity, count;
    Node* head, *tail;

    LRUCache(int c){
        capacity=c;
        head=new Node(0,0);
        tail=new Node(0,0);
        tail->pre=head;
        tail->next=NULL;
        head->next=tail;
        head->pre=NULL;
        count=0;
    }

    void deleteNode(Node* node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
    }

    void addToHead(Node* node){
        node->next=head;
        node->pre=NULL;
        head->pre=node;
        head=node;
    }

    int get(int key){
        if(map[key]!=NULL){
            Node* node=map[key];
            int result=node->val;
            deleteNode(node);
            addToHead(node);
            cout<<"value for the key "<<key<<" is"<<result<<endl;
            return result;
        }
        else{
            return -1;
        }
    }

    void set(int key, int val){
        if(map[key]!=NULL){
            Node* node=map[key];
            node->val=val;
            deleteNode(node);
            addToHead(node);
        }
        else{
            Node* node=new Node(key,val);
            map[key]=node;
            if(count<capacity){
                count++;
                addToHead(node);
            }
            else{
                map.erase(tail->pre->key);
                deleteNode(tail->pre);
                addToHead(node);
            }
        }
    }
};

int main(){
    { 
		
		LRUCache cache(2); 

		// it will store a key (1) with value 
		// 10 in the cache. 
		cache.set(1, 10); 

		// it will store a key (2) with value 20 in the cache. 
		cache.set(2, 20); 
		cout<<"Value for the key: 1 is " << cache.get(1)<<endl; // returns 10 

		// removing key 1 and store a key (3) with value 30 in the cache. 
		cache.set(3, 30); 

		cout<<"Value for the key: 2 is " << 
				cache.get(2)<<endl; // returns 20

		// removing key 2 and store a key (4) with value 40 in the cache. 
		cache.set(4, 40); 
		cout<<"Value for the key: 1 is " << 
			cache.get(2)<<endl; // returns -1 (not found) 
		cout<<"Value for the key: 3 is " << 
						cache.get(3)<<endl; // returns 30 
		cout<<"Value for the key: 4 is " << 
						cache.get(4)<<endl; // return 40 
						
		return 0;
	} 
}
