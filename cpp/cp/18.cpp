#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[2*n];
    int i=0;
    while(i<2*n)
    {
        cin>>arr[i];
        i++;
    }
    int a=arr[0];
    int groups=1;
    for(int j=0;j<(2*n)-1;j=j+2){
        if(arr[0]!=arr[j]){
            arr[0]=arr[j];
            groups++;
        }
    }
    cout<<groups;
    return 0;
} // namespace std;

