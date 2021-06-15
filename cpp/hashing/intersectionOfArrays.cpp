#include<iostream>
#include<unordered_set>
#include<vector>
#include<iterator>
using namespace std;
int intersection(vector<int> a, vector<int> b){
    unordered_set<int> s1, s2;
    for(int i=0;i<a.size();i++){
        s1.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){
        s2.insert(b[i]);
    }
    int res=0;
    unordered_set<int> ::iterator i;
    for(i=s1.begin();i!=s1.end();i++){
        if(s2.find(*i)!=s2.end()){
            //s1.erase(*i);
            s2.erase(*i);
            res++;
        }
    }
    return res;
}
int main(){
    vector<int> a;
    a.push_back(4);
    a.push_back(4);
    a.push_back(5);
    a.push_back(5);
    a.push_back(6);
    a.push_back(2);
    a.push_back(7);
    a.push_back(6);
    vector<int> b;
    b.push_back(4);
    b.push_back(4);
    b.push_back(5);
    b.push_back(5);
    b.push_back(6);
    b.push_back(2);
    
    cout<<intersection(a,b);
    return 0;
}