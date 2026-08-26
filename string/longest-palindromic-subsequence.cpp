// class Solution {
// public:
//     int solve(int start, int end, string &s) {
//         if(start > end)
//             return 0;

//         if(start == end)
//             return 1;

//         if(s[start] == s[end])
//             return 2 + solve(start+1, end-1, s);

//         return max(
//             solve(start+1, end, s),
//             solve(start, end-1, s)
//         );
//     }
//     int longestPalindromeSubseq(string s) {
//         return solve(0, s.length()-1, s);
//     }
// };



//mem
class Solution {
  public:
    
    int solve(int st, int end, string &s, vector<vector<int>> &dp) {
        if(st > end)
            return 0;
        
        if(st == end)
            return 1;
        
        if(dp[st][end] != -1)
            return dp[st][end];
        
        if(s[st] == s[end])
            return dp[st][end] = 2 + solve(st+1, end-1, s, dp);
        
        return dp[st][end] = max(
            solve(st+1, end, s, dp),
            solve(st, end-1, s, dp)
        );
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(0, n-1, s, dp);
    }
};