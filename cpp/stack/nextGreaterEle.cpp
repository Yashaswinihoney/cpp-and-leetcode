#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//method 1, using the same concept as prev greater ele but iterating the array from the end
void nextGreater(vector<int> v){
    vector<int> res;
    stack<int> s;
    s.push(v.size()-1);
    res.push_back(-1);
    for(int i=v.size()-2;i>=0;i--){
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
    reverse(res.begin(),res.end());
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
    nextGreater(v);
    return 0;
}