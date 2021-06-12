#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*int val(char c){
    if(c=='('){
        return 1;
    }
    else if(c=='{'){
        return 2;
    }
    else if(c=='['){
        return 3;
    }
    else{
        return -1;
    }
}*/
bool check(string s){
    stack<char> stack;

        if(s.length() == 0){
            return true;
        }
        if(s.length() == 1){
            return false;
        }
    
        for(int i =0 ; i < s.length(); i++){
            char c = s[i];
            cout << c;
            if(c == '}'|| c == ')' || c == ']'){
                if(stack.size() == 0 ) return false;
                if(c == '}' && stack.top() != '{') return false;
                if(c == ')' && stack.top() != '(') return false;
                if(c == ']' && stack.top() != '[') return false;
                stack.pop();
            
            } 
            else {
                stack.push(c);
            }
        }
        cout << "reached end";
        if(stack.size() == 0) return true;
        return false;
    }
    /*stack<char> st;
    bool ans=true;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='{'||c=='['||c=='('){
            st.push(c);
        }
        else if (c==')')
        {
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if (c=='}')
        {
            if(!st.empty()&&st.top()=='{'){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if (c==']')
        {
            if(!st.empty()&&st.top()=='['){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        
    }
    return ans;*/

int main(){
    cout<<to_string(check("(("));
    return 0;
}