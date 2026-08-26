class Solution {
public:

    int solve(int st, int end, string & s, vector<vector<int>> &dp){
        if(st>=end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        if(s[st]==s[end]) return dp[st][end] = solve(st+1,end-1,s,dp);
        return dp[st][end] = 1 + min(solve(st+1,end,s,dp), solve(st,end-1,s,dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,n-1,s,dp);
    }
};