#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};