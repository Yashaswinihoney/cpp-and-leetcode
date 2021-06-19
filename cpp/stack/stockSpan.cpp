#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void stockSpan(vector<int> v){
    vector<int> res;
    stack<int> s;
    s.push(0);
    res.push_back(1);
    for(int i=1;i<v.size();i++){
        if(s.empty()==true){
            s.push(i);
        }
        int n;
        while(!s.empty()&&v[s.top()]<v[i]){
            s.pop();
        }
        if(s.empty()==true){
            n=i+1;
        }
        if(!s.empty()){
            n=i-s.top();
        }
        res.push_back(n);
        s.push(i);
        /*if(!s.empty()&&v[s.top()]>v[i]){
            s.push(i);
        }*/
    }

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return;
}
int main(){
    vector<int> v;
    v.push_back(30);
    v.push_back(20);
    v.push_back(25);
    v.push_back(28);
    v.push_back(27);
    v.push_back(29);
    stockSpan(v);
    return 0;
}