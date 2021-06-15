#include<iostream>
#include<vector>
#include<list>
using namespace std;

//chaining use lists
class myHash{
    public:
    int bucket;
    list<int> *table;

    myHash(int b){
        bucket=b;
        table=new list<int>[b];
    }

    void insert(int key){
        int i=key%bucket;
        table[i].push_back(key);
    }

    bool search(int key){
        int i=key%bucket;
        for(auto x: table[i]){
            if(x==key) return true;
            return false;
        }
    }

    void remove(int key){
        int i=key%bucket;
        table[i].remove(key);
    }
};
int main(){

}