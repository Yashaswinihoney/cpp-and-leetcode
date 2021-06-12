/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int r=0;
    int count=0;
    while(n/10){
        r=n%10;
        if(r==4||r==7){
            count++;
        }
        n=n/10;

    }
    while(count/10){
        r=count%10;
        if(!((r==4)||(r==7))||r==0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}*/

#include<iostream>
#include<cmath>
using namespace std;
int check(int n){
    if(n==4||n==7){
        return 1;
    }
    else{
        return 0;
    }
    int r;
    r=n%10;
    if(!(r==4)||(r==7)){
        return 0;
    }
    check(n/10);
    return 1;
}
int main(){
    int n,len;
    cin>>n;
    len=log10(n)+1;
    if(check(n)&&check(len)){
        cout<<"YES";
        return 0;
    }
    else{
        cout<<"NO";
        return 0;
    }
}