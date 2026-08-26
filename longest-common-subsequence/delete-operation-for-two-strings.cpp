class Solution {
public:

    int solve(int i,int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i==s1.length()-1 && j>s2.length()-1) return s1.length()-i;
        if(j==s2.length()-1 && i>s1.length()-1) return s2.length()-i;
        if(i>=s1.length() || j>=s2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] = solve(i+1,j+1,s1,s2,dp);
        return dp[i][j] = 2 + min(solve(i+1,j,s1,s2,dp), solve(i,j+1,s1,s2,dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(
            word1.size(),
            vector<int>(word2.size(),-1)
        );
        return solve(0,0,word1,word2,dp);
    }
};



//alternate approach through longest common subsequence
// class Solution {
// public:
//     int solve(int i, int j, string &text1, string &text2,
//               vector<vector<int>> &dp){
//         if(i>=text1.size() || j>=text2.size()) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(text1[i]==text2[j])
//             return dp[i][j] = 1+solve(i+1,j+1,text1,text2,dp);
//         return dp[i][j] = max(
//             solve(i+1,j,text1,text2,dp),
//             solve(i,j+1,text1,text2,dp)
//         );
//     }
//     int minDistance(string text1, string text2) {
//         vector<vector<int>> dp(
//             text1.size(),
//             vector<int>(text2.size(),-1)
//         );
//         int longestSubsequence = solve(0,0,text1,text2,dp);
//         return (text1.size() - longestSubsequence) + (text2.size() - longestSubsequence);
//     }
// };