class Solution {
public:
    int solve(int i, int n, vector<int> &dp){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];

        int a = solve(i+1,n,dp);
        int b = solve(i+2,n,dp);
        dp[i] = a+b;
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return solve(0,n,dp);
    }
};