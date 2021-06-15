#include<unordered_set>
#include<iostream>
#include<vector>
using namespace std;
bool subarray(vector<int> v, int n){
    unordered_set<int > s;
    int presum=0;
    for(int i=0;i<v.size();i++){
        presum+=v[i];
        // since if the given presum alredy exists in the set then obviously there had been a subaarya/ element whose sum is 0/the element is zero
        if(s.find(presum)!=s.end()) return true;
        if(presum==0) return true;
        s.insert(presum);
    }
    return false;
}