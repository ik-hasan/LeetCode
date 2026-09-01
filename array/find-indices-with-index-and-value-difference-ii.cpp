class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        int minIndex =0,maxIndex=0;
        for(int i=id;i<nums.size();i++){
            int j = i-id;

            if(nums[j] < nums[minIndex]) minIndex = j;
            if(nums[j] > nums[maxIndex]) maxIndex = j;

            if(abs(nums[i]-nums[minIndex]) >= vd) return {minIndex,i}; 
            if(abs(nums[i]-nums[maxIndex]) >= vd) return {maxIndex,i}; 
        }   
        return {-1,-1};
    }
};