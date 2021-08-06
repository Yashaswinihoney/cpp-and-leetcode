#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int arr[6];
        int s1=0;
        int s2=0;
        for(int i=0;i<6;i++){
            cin>>arr[i];
            if(i<3){
                s1+=arr[i];
            }
            else{
                s2+=arr[i];
            }
        }
        if(s1>s2){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
    return 0;
}