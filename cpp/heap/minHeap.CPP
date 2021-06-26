#include<iostream>
#include<utility>
#define INT_MIN -100
using namespace std;
class MinHeap{
    public:
    int *arr;
    int size;
    int cap;

    MinHeap(int c){
        cap=c;
        size=0;
        arr=new int[c];
    }

    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return(2*i+2);
    }
    int parent(int i){
        return((i-1)/2);
    }

    void insert(int n){
        if(cap==size) return;

        size++;
        arr[size-1]=n;

        for(int i=size-1;i!=0&&arr[parent(i)]>arr[i];){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }

    void minHeapify(int i){
        int l=left(i), r=right(i), smallest=i;

        if(l<size&&arr[l]<arr[i]){
            smallest=l;
        }
        if(r<size&&arr[r]<arr[smallest]){
            smallest=r;
        }
        if(smallest!=i){
            swap(arr[i],arr[smallest]);
            minHeapify(smallest);
        }
    }

    int getMin(){
        return arr[0];
    }

    int extractMin(){
        if(size<=0) return -1;
        if(size==1){
            size--;
            return arr[0];
        }
        swap(arr[0],arr[size-1]);
        size--;
        minHeapify(0);
        return arr[size];
    }

    void decreasekey(int i, int x){
        arr[i]=x;
        while(i!=0&&arr[parent(i)]>arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    void deleteKey(int i){
        decreasekey(i,INT_MIN);
        extractMin();
    }

    //using min heap
    void BuildHeap(){
        for(int i=(size-2)/2;i>=0;i--){
            minHeapify(i);
        }    
    }

    void maxHeapify(int arr[], int n, int i){
        int largest=i, l=left(i), r=right(i);

        if(l<n&&arr[l]>arr[i]){
            largest=l;
        }
        if(r<n&&arr[r]>arr[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            maxHeapify(arr, n, largest);
        }
    }
};