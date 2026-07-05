class Solution {
public:

    int solve(vector<int>& nums, int target, int i, vector<int> &dp ){
        if(i==nums.size()-1) return 0;
        if(dp[i]!=-2) return dp[i];

        int inc = 0;
        int ans = -1;
        for(int j=i+1;j<nums.size();j++){
            if( nums[j]-nums[i] <= target && nums[j]-nums[i] >= -target){
                inc = solve(nums,target,j,dp);
                if(inc!=-1) ans = max(ans,1+inc);
            }
        }
        dp[i]=ans;
        return dp[i];
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-2);
        int ans = solve(nums,target,0,dp);
        return (ans==INT_MAX) ? -1 : ans;
    }
};

































