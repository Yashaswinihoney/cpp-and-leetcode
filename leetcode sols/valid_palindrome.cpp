class Solution {
public:
    bool isPalindrome(string s) {
        string curr="";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])) curr+=s[i];
        }
        transform(curr.begin(),curr.end(),curr.begin(),::tolower);
        //string t=curr;
        //reverse(curr.begin(),curr.end());
        //return(t==curr);
        int i=0, j=curr.size()-1;
        while(i<=j){
            if(curr[i]!=curr[j]) return false;
            i++; j--;
        }
        return true;
    }
};