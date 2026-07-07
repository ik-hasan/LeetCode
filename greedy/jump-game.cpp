class Solution {
public:
    
    bool solve(vector<int>& nums,int index,vector<int> &dp){
        if(index == nums.size() ) return false;
        if(index == nums.size()-1 ) return true;
        if(dp[index]!=-1) return dp[index];
        bool ans = false;
        for(int i = 1; i<=nums[index]; i++){
            ans = ans || solve(nums,index+i,dp);
            if(ans) return true;
        }
        dp[index]=ans;
        return dp[index];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};