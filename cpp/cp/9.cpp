/*#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int i=0,u=0,l=0;
    while(i<s.length()){
        if(s[i]>=65 &&s[i<=90]){
            u++;
        }
        else{
            l++;
        }
    }
    if (l>=u)
    {
        transform(s.begin(),s.end(),s.begin(), ::tolower);
    }
    else{
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    cout<<s;
    return 0;
    
}*/
#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char a[110];
    int up=0,lo=0;
    cin>>a;
    for(int i=0;a[i]!=NULL;i++){(isupper(a[i]))?up++:lo++;}
    (up>lo)?cout<<strupr(a):cout<<strlwr(a);
    return 0;
}