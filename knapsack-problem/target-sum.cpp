class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int sum, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return (sum == target);
        }

        if (dp[i][sum + 1000] != -1)
            return dp[i][sum + 1000];

        int plus = solve(i + 1, sum + nums[i], nums, target);
        int minus = solve(i + 1, sum - nums[i], nums, target);

        return dp[i][sum + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.assign(nums.size(), vector<int>(2001, -1));

        return solve(0, 0, nums, target);
    }
};