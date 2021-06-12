#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}
void prefixToInfix(string s){
    stack<string> st;
    for(int i=s.length()-1;i>0;i--){
        if(isOperator(s[i])){
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string res;
            res=op1+s[i]+op2;
            st.push(res);
        }
        else{
            st.push(string(1,s[i]));
       }
    }
    cout<<st.top();
}
int main(){
    prefixToInfix("*-A/BC-/AKL");
    return 0;
}