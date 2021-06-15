#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;
bool subArray(vector<int> v, int sum){
    unordered_set<int> s;
    int presum=0;
    for(int i=0;i<v.size();i++){
        presum+=v[i];
        if(presum==sum) return true;
        if(s.find(sum-presum)!=s.end()) return true;
        s.insert(presum);
    }
    return false;
}