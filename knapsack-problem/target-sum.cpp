class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, int target) {
        if(i==nums.size() && sum==target) return 1;
        if(i>=nums.size()) return 0;

        int add = solve(i+1,sum+nums[i],nums,target);
        int sub = solve(i+1,sum-nums[i],nums,target);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};