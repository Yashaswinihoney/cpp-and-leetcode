#include<iostream>
using namespace std;
int main(){
    long int t;
    cin>>t;
    while(t--){
        long int r,b,d;
        cin>>r>>b>>d;
        if(r==b&&d==0){
            cout<<"YES"<<endl; 
        }
        else if((r==1&&b!=1)||(r!=1&&b==1)||(d==0)){
            cout<<"NO"<<endl; 
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t,r,b,d;
	cin>>t;
	while(t--){
		cin>>r>>b>>d;
		if(r>b)swap(r,b);
		if(r*(1+d)>=b)printf("YES\n");
		else printf("NO\n");
	}
}*/