#include<iostream>
#include<vector>
using namespace std;
//-1 means empty, -2 means deleted
//linear probing
class myHash{
    public:
    int cap,size;
    vector<int> v;

    myHash(int x){
        cap=x;
        size=0;
        for(int i=0;i<x;i++){
            v.push_back(-1);
        }
    }
    int hash(int key){
        return(key%cap);
    }

    bool search(int key){
        int h=key%cap;
        int i=h;
        while (v[i]!=-1)
        {
            if(v[i]==key) return true;
            i=(i+1)%cap;
            if(i==h) return false;
        }
        return false;
    }

    bool insert(int key){
        if(size==cap) return false;
        int h=key%cap;
        while(v[h]>0&&v[h]!=key){
            h=(h+1)%cap;
        }
        if(v[h]==key) return false;
        else{ 
            v[h]=key;
            size++;
        }
        return true;
    }

    bool erase(int key){
        if(size==0) return false;
        int h=key%cap;
        int i=h;
        while(v[i]!=-1){
            if(v[i]==key){
                v[i]=-1;
                return true;
            }
            i=(i+1)%cap;
            if(i==h) return false;
        }
        return false;
    }
};
int main(){

}