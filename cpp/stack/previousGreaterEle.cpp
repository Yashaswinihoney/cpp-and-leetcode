#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void prevGreater(vector<int> v){
    vector<int> res;
    stack<int> s;
    s.push(0);
    res.push_back(-1);
    for(int i=1;i<v.size();i++){
        if(s.empty()){
            s.push(i);
        }
        while(!s.empty()&&v[s.top()]<v[i]){
            s.pop();
        }
        if(s.empty()){
            res.push_back(-1);
        }
        if(!s.empty()){
            res.push_back(v[s.top()]);
        }
        s.push(i);
    }

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return;
}
int main(){
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(10);
    v.push_back(5);
    v.push_back(15);
    //v.push_back(29);
    prevGreater(v);
    return 0;
}