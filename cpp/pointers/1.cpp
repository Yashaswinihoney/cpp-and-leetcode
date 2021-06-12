#include<iostream>
using namespace std;
int main()
{
    int arr[4]={10,20,30,40};
    //for(int i=0;i<4;i++){
      //  cout<<*(arr+i)<<endl;
    //}
    int *ptr=arr;
    for(int i=0;i<4;i++){
        cout<<*ptr<<endl;
        ptr++;
    }
    return 0;
    
} // namespace std;

