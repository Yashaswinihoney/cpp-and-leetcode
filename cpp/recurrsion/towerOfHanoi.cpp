#include <iostream>
#include <vector>
using namespace std;
//int res;
void tower(int n, char s, char a, char d){
    if(n==1){
        cout<<"move disk "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }

    //res+=1;
    tower(n-1,s,d,a);
    cout<<"move disk "<<n<<" from "<<s<<" to "<<a<<endl;
    //res+=1;
    tower(n-1,a,s,d);
    //return res;
}
int main(){
    int n=4;
    //res=0;
    //char s, a, d;
    
    tower(n,'S','A','D');
    //cout<<res;
    return 0;
}