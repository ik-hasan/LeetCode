// class Solution {
// public:
//     int solve(int i, int sum, vector<int>& nums, int target) {
//         if(i==nums.size() && sum==target) return 1;
//         if(i>=nums.size()) return 0;

//         int add = solve(i+1,sum+nums[i],nums,target);
//         int sub = solve(i+1,sum-nums[i],nums,target);
//         return add+sub;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return solve(0,0,nums,target);
//     }
// };


//mem
// class Solution {
// public:
//     int solve(int i, int sum, vector<int>& nums, int target,
//               vector<vector<int>>& dp, int offset) {

//         if(i==nums.size() && sum==target) return 1;
//         if(i>=nums.size()) return 0;

//         if(dp[i][sum+offset] != -1)
//             return dp[i][sum+offset];

//         int add = solve(i+1,sum+nums[i],nums,target,dp,offset);
//         int sub = solve(i+1,sum-nums[i],nums,target,dp,offset);

//         return dp[i][sum+offset] = add+sub;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {

//         int totalSum = accumulate(nums.begin(),nums.end(),0);

//         if(abs(target)>totalSum) return 0;

//         vector<vector<int>> dp(
//             nums.size(),
//             vector<int>(2*totalSum+1,-1)
//         );

//         return solve(0,0,nums,target,dp,totalSum);
//     }
// };



//tab
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>totalSum) return 0;
        int offset = totalSum;
        vector<vector<int>> dp(
            n+1,
            vector<int>(2*totalSum+1,0)
        );
        dp[n][target+offset] = 1;

        for(int i=n-1;i>=0;i--) {
            for(int sum=-totalSum;sum<=totalSum;sum++) {

                int add = 0;
                int sub = 0;
                if(sum+nums[i]>=-totalSum &&
                   sum+nums[i]<=totalSum) {
                    add = dp[i+1][sum+nums[i]+offset];
                }
                if(sum-nums[i]>=-totalSum &&
                   sum-nums[i]<=totalSum) {
                    sub = dp[i+1][sum-nums[i]+offset];
                }
                dp[i][sum+offset] = add+sub;
            }
        }
        return dp[0][offset];
    }
};



