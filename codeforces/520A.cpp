#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	//if(n<26) cout<<"NO"; return 0;
	string s;
	cin>>s;
	transform(s.begin(),s.end(),s.begin(),::tolower);
	set<char> res;
	for(int i=0;i<s.length();i++){
	    res.insert(s[i]);
	}
	(res.size()>=26)?(cout<<"YES"):(cout<<"NO");
	return 0;
}