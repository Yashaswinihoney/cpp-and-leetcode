#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^'){
        return true;
    }
    else{
        return false;
    }
}
void postToIn(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if(isOperator(s[i])){
            string op2=st.top();
            st.pop();
            string op1=st.top();
            st.pop();
            string res=op1+s[i]+op2;
            st.push(res);
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    cout<<st.top();
}
int main(){
    postToIn("ab*c+");
    return 0;
}