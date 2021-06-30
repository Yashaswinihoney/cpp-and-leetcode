#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void kLargest(vector<int> v, int n, int k){

    priority_queue <int,vector<int>,greater<int> > minHeap;
	for(int i = 0; i < k; i++)
	{
		minHeap.push(v[i]);
	}
	for(int i = k; i < n; i++)
	{
		if (minHeap.top() > v[i])
			continue;
		else
		{
			minHeap.pop();
			minHeap.push(v[i]);
		}
	}
	
	while(minHeap.empty()==false){
	    cout<<minHeap.top()<<" ";
	    minHeap.pop();
	}
    
    /*priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0;i<k;i++){
        pq.push(v[i]);
    }
    for(int i=k;i<n;i++){
        if(pq.top()>v[i]){
            continue;
        }
        else{
            pq.pop();
            pq.push(v[i]);
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }*/
}

int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(15);
    v.push_back(10);
    v.push_back(20);
    v.push_back(8);
    v.push_back(25);
    v.push_back(18);
    int n=sizeof(v)/sizeof(v[0]);
    int k=3;
    kLargest(v,n,k);
    return 0;
}