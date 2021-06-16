class Solution {
public:
    int findPoisonedDuration(vector<int>& T, int D) {
        int sum=0;
        for(int i=0;i<T.size()-1;i++){
            if(T[i+1]<=T[i]+D-1){
                sum+=T[i+1]-T[i];
            }
            else{
                sum+=D;
            }
        }
        return sum+D;
    }
};