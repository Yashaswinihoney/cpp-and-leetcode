class Solution {
public:
    bool halvesAreAlike(string s) {
        int st=s.size();
        st=st/2;
        int n=0,n2=0;
        for(int i=0;i<st;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                n++;
            }
        }
        for(int i=st;i<2*st;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                n2++;
            }
        }
        return(n==n2);
    }
};