class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> res;
        int n=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                n++;
            }
            if(nums[i]==0||i==nums.size()-1){
                res.push_back(n);
                n=0;
            }
        }
        sort(res.begin(),res.end());
        return(res[res.size()-1]);
    }
};