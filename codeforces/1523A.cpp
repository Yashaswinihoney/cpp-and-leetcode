#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l, n;
        cin>>l>>n;
        string s,s1;
        cin>>s;
        s=" "+s;
        while(n--){
            s1=s;
			for(int i=1;i<=l;i++)
			{
				if(s[i]=='0'&&(s1[i-1]=='1')+(s1[i+1]=='1')==1)
					s[i]='1';
			}
			if(s==s1) break;
        }
        for (int i = 1; i <= l; i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}