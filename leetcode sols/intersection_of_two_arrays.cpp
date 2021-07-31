class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        int i=nums1.size()-1;
        while(i>=0){
            if(find(nums2.begin(),nums2.end(),nums1[i])!=nums2.end()){
                s.insert(nums1[i]);
            }
            i--;
        }
        vector<int> v;
        for(auto it:s){
            v.push_back(it);
        }
        return v;
    }
};