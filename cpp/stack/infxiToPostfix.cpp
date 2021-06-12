#include<iostream>
#include<stack>
#include<string>
using namespace std;
int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
void infixToPostfix(string s){
    stack<char> st;
    string res;
    
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'||c<='9')){
            res+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty()&&st.top()!='(')
            {    
                char t =st.top();
                st.pop();
                res+= t;
            }    
            st.pop();
        }
        else{
            while(!st.empty()&&prec(s[i]<=st.top())){
                char t=st.top();
                st.pop();
                res+=t;
            }
            st.push(c);
        }

    }
    while(!st.empty()){
        char t=st.top();
        st.pop();
        res+=t;
    }
    cout<<res;
}
int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(s);
    return 0;
}