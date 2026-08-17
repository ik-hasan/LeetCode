// class Solution {
// public:

//     int solve(int i, int j, string &text1, string &text2){
//         if(i>=text1.size() || j>=text2.size()) return 0;
//         if(text1[i]==text2[j]) return 1+solve(i+1,j+1,text1,text2);

//         return max(solve(i+1,j,text1,text2), solve(i,j+1,text1,text2));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         return solve(0,0,text1,text2);
//     }
// };


//mem
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

//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int>> dp(
//             text1.size(),
//             vector<int>(text2.size(),-1)
//         );

//         return solve(0,0,text1,text2,dp);
//     }
// };



//tab
// class Solution {
// public:

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
//         vector<vector<int>> dp(
//             n+1,
//             vector<int>(m+1,0)
//         );
//         for(int i=n-1;i>=0;i--){
//             for(int j=m-1;j>=0;j--){
//                 if(text1[i]==text2[j])
//                     dp[i][j] = 1+dp[i+1][j+1];
//                 else
//                     dp[i][j] = max(
//                         dp[i+1][j],
//                         dp[i][j+1]
//                     );
//             }
//         }
//         return dp[0][0];
//     }
// };



//so
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();
        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j])
                    curr[j] = 1+next[j+1];
                else
                    curr[j] = max(
                        next[j],
                        curr[j+1]
                    );
            }
            next = curr;
        }
        return next[0];
    }
};
