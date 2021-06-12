#include<iostream>
using namespace std;
void swap(int *x, int *y){
    int t;
    t=*y;
    *y=*x;
    *x=t;
}
int main()
{
    int a,b;
    cin>>a>>b;
    swap(&a,&b);
    cout<<a<<" "<<b;
    return 0;
} // namespace std;

