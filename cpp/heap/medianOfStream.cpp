#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void median(vector<int> v){
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int> > g;
    s.push(v[0]);
    for(int i=1;i<v.size();i++){
        int x=v[i];
        if(s.size()>g.size()){
            if(s.top()>x){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else{
                g.push(x);
            }
        }
        else{
            if(x<=s.top()) s.push(x);
            else{
                g.push(x);
                s.push(g.top());
                g.pop();
            }
        }
    }
    if(s.size()==g.size()){
        cout<<(s.top()+g.top())/2.0;
    }
    else{
        cout<<s.top();
    }
}
int main(){
    vector<int> v;
    v.push_back(25);
    v.push_back(7);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    median(v);
    return 0;
}