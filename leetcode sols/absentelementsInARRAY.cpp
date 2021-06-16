class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s1;
        for(int i=1;i<=nums.size();i++){
            s1.insert(i);
        }
        set<int> s2(nums.begin(),nums.end());
        vector<int> res;
        auto i=s1.begin(), j=s2.begin();
        while(i<s1.end()&&j<s2.end()){
            if(*i!=*j){
                res.push_back(*i);
                i++;
            }
            else{
                i++; j++;
            }
        }
        while(i<s1.end()){
            res.push_back(*i);
            i++;
        }
        return res;
    }
};