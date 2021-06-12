#include<iostream>
using namespace std;
int main()
{
    int n,h;
    cin>>n>>h;
    int w=0;
    while(n--){
        int a;
        cin>>a;
        if(a>h){
            w+=2;
        }
        else{
            w+=1;
        }
    }
    cout<<w;
    return 0;
} // namespace std;
