#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Pair{
    public:
    int min;
    int max;
};

Pair getMinMax(vector<int> arr, int l, int r){
    Pair minmax, m1, m2;
    int mid;

    if(l==r){
        minmax.min = arr[l];
        minmax.max = arr[r];
        return minmax;
    }

    if(r==l+1){
        minmax.min = min(arr[l],arr[r]);
        minmax.max = max(arr[r],arr[l]);
        return minmax;
    }

    mid=l+(r-l)/2;
    m1=getMinMax(arr,l,mid);
    m2=getMinMax(arr,mid+1,r);

    minmax.min=min(m1.min,m2.min);
    minmax.max =max(m1.max,m2.max);
    return minmax;
}
int main(){
    vector<int> arr;
    arr.push_back(1000);
    arr.push_back(11);
    arr.push_back(445);
    arr.push_back(1);
    arr.push_back(330);
    arr.push_back(3000);

    int size=6;

    Pair min_max=getMinMax(arr,0,size-1);

    cout<<min_max.min<<endl;
    cout<<min_max.max<<endl;
    return 0;
}

