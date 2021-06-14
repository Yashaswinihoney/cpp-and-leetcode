class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums[0];
        for(int i=0;i<nums.size();i++){
            n=n^nums[i];
        }
        n=n^nums[0];
        return n;
    }
};