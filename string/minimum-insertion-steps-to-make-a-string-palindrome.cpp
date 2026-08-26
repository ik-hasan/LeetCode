// class Solution {
// public:

//     int solve(int st, int end, string & s, vector<vector<int>> &dp){
//         if(st>=end) return 0;
//         if(dp[st][end]!=-1) return dp[st][end];
//         if(s[st]==s[end]) return dp[st][end] = solve(st+1,end-1,s,dp);
//         return dp[st][end] = 1 + min(solve(st+1,end,s,dp), solve(st,end-1,s,dp));
//     }
//     int minInsertions(string s) {
//         int n = s.length();
//         vector<vector<int>> dp(n,vector<int> (n,-1));
//         return solve(0,n-1,s,dp);
//     }
// };



//tab
class Solution {
public:

    int minInsertions(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int st = n-1; st >= 0; st--) {
            for(int end = st+1; end <= n-1; end++) {

                if(s[st] == s[end])
                    dp[st][end] = dp[st+1][end-1];

                else
                    dp[st][end] = 1 + min(
                        dp[st+1][end],
                        dp[st][end-1]
                    );
            }
        }

        return dp[0][n-1];
    }
};