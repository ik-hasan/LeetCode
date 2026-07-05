// class Solution {
// public:
//     int solve(vector<int>& nums, int target, int index){
//         if(target==0) return 0;
//         if(index>=nums.size()) return INT_MIN;
//         int inc = INT_MIN;
//         int ans = INT_MIN;
//         if(nums[index] <=target){
//             int res = solve(nums,target-nums[index],index+1);
//             if(res!=INT_MIN) inc = 1+res;
//         }
//         int exc = solve(nums,target,index+1);

//         ans = max(inc,exc);
//         return ans;
//     }
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
//         int ans = solve(nums,target,0);
//         return (ans==INT_MIN) ? -1 : ans;
//     }
// };   

class Solution {
public:
    int solve(vector<int>& nums, int target, int index,vector<vector<int>> &dp){
        if(target==0) return 0;
        if(index>=nums.size()) return INT_MIN;
        int inc = INT_MIN;
        // int ans = INT_MIN;

        if(dp[index][target]!=-1) return dp[index][target];
        if(nums[index] <=target){
            int res = solve(nums,target-nums[index],index+1,dp);
            if(res!=INT_MIN) inc = 1+res;
        }
        int exc = solve(nums,target,index+1,dp);

        // ans = max(inc,exc);
        dp[index][target]=max(inc,exc);
        return dp[index][target];
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1)); 
        int ans = solve(nums,target,0,dp);
        return (ans==INT_MIN) ? -1 : ans;
    }
};   