class Solution {
public:

    bool solve(int i, int sum, vector<int>& nums, vector<vector<int>> &dp){
        if(i>=nums.size() || sum<0) return false;
        if(sum==0) return true;
        if(dp[i][sum] != 0) return dp[i][sum];

        dp[i][sum] = solve(i+1,sum,nums,dp) || solve(i+1,sum-nums[i],nums,dp);
        return dp[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2) return false;
        int sum = totalSum/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>((totalSum/2)+1,0));

        return solve(0,sum,nums,dp);
    }
};