class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        

        for(int i=0;i<nums.size();i++){
            int j = indexDifference + i;
            while(j<nums.size()){
                 if( abs(nums[i] - nums[j]) >= valueDifference) {
                    return {i,j};
                }
                j++;
            }
        }
        return {-1,-1};
    }
};