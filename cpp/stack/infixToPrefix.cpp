#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int prec(char c){
    if(c=='^'){
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
void infixtoPrefix(string s){
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
    string res;
    stack<char> st;

    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            res+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty()&&st.top()!='('){
                char temp=st.top();
                st.pop();
                res+=temp;
            }
            st.pop();
        }
        else{
            while (!st.empty()&& prec(c)<=prec(st.top()))
            {
                char temp=st.top();
                st.pop();
                res+=temp;
            }
            st.push(c);    
        }
    }
    while (!st.empty())
    {
        char temp=st.top();
        st.pop();
        res+=temp;
    }

    reverse(res.begin(),res.end());
    cout<<res;
    
}
int main(){
    //infixtoPrefix("a+b*c+d");
    //infixtoPrefix("(a+b)*(c+d)");
    infixtoPrefix("x+y*z/w+u");
    return 0;
}
