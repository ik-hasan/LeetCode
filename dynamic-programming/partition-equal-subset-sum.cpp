class Solution {
public:

    bool solve(int i, int sum, vector<int>& nums){
        if(i>=nums.size() || sum<0) return false;
        if(sum==0) return true;

        return solve(i+1,sum,nums) || solve(i+1,sum-nums[i],nums);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2) return false;
        int sum = totalSum/2;

        return solve(0,sum,nums);
    }
};