#include <iostream>
using namespace std;

void p(int n){
    int d=2*n;
    int s=n-1;
    int t=s;
    int dest=2*s;
    int count=1;
    while(s<=dest){
        for(int i=0;i<count;i++){
            cout<<s<<" ";
        }
        cout<<endl;
        count++;
        s++;
    }
    
    while(s>=t&&count>=1){
        for(int i=0;i<count;i++){
            cout<<s<<" ";
        }
        cout<<endl;
        count--;
        s--;
    }
}
int main(){
    int n;
    cin>>n;
    p(n);
	return 0;
}