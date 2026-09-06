class Solution {
public:

    //BRUTE FORCE
    // int solve(string& s, string& t, string ans, int i){
    //     if(i == s.size()){
    //         if(ans==t) return 1;
    //         return 0;
    //     }

    //     int inc = solve(s, t, ans + s[i], i + 1);
    //     int exc = solve(s, t, ans, i + 1);

    //     return inc + exc;
    // }

    // int numDistinct(string s, string t) {
    //     return solve(s, t, "", 0);
    // }



    //REC WITH TLE
    // int solveRec(string& s, string& t, int i, int j){

    //     if(i>=s.size() && j>=t.size()) return 1; 
    //     if(i>=s.size() && j<t.size()) return 0; 

    //     int inc = 0;
    //     if(s[i]==t[j]){
    //         inc = solveRec(s,t,i+1,j+1);
    //     }
    //     int exc = solveRec(s,t,i+1,j);
    //     return inc+exc;
    // }

    // int numDistinct(string s, string t) {
    //     return solveRec(s, t, 0, 0);
    // }



    //MEMOIZATION
    // int solveMem(string& s, string& t, int i, int j,vector<vector<int>> &dp){

    //     if(i>=s.size() && j>=t.size()) return 1; 
    //     if(i>=s.size() && j<t.size()) return 0; 

    //     if(dp[i][j] != -1) return dp[i][j];
    //     int inc = 0;
    //     if(s[i]==t[j]){
    //         inc = solveMem(s,t,i+1,j+1,dp);
    //     }
    //     int exc = solveMem(s,t,i+1,j,dp);

    //     dp[i][j]=inc+exc;
    //     return dp[i][j];
    // }

    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return solveMem(s, t, 0, 0,dp);
    // }



    //TABULATION
    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n+2,vector<int>(m+2,0));

    //     dp[n][m] = 1;

    //     for(int i=n-1;i>=0;i--){
    //         for(int j=m;j>=0;j--){
    //             long long inc = 0;
    //             if(s[i]==t[j]){
    //                 inc = dp[i+1][j+1];
    //             }
    //             long long exc = dp[i+1][j];

    //             dp[i][j]=inc+exc;
    //         }
    //     }
    //     return dp[0][0];
    // }



    //SPACE OPTIMIZATION
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);

        next[m] = 1;

        for(int i=n-1;i>=0;i--){
            for(int j=m;j>=0;j--){
                long long inc = 0;
                if(s[i]==t[j]){
                    inc = next[j+1];
                }
                long long exc = next[j];

                curr[j]=inc+exc;
            }
            next=curr;
        }
        return curr[0];
    }
};
