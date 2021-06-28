#include<iostream>
using namespace std;
void postOrder(int pre[], int* index, int min, int max, int size){
    if(*index>=size) return;

    if(pre[*index]<min||pre[*index]>max) return;

    int val=pre[*index];
    *index=*index+1;
    
    postOrder(pre,index,min,val,size);
    postOrder(pre,index,val,max,size);
    cout<<val<<" ";
        
}
void postORDER(int pre[], int size){
    int index=0;
    postOrder(pre,&index,-100,100,size);
}
int main(){
    int pre[]={40,30,35,80,100};
    int n=sizeof(pre)/sizeof(pre[0]);
    postORDER(pre,n);
    return 0;
}