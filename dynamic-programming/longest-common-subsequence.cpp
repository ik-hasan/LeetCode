class Solution {
public:

    //BASIC REC SOLN WITH TLE
    // int solve(string text1, string text2,int i,int j){

    //     if( i>=text1.length() || j>=text2.length()) return 0;
    //     int ans = 0;
    //     if(text1[i]==text2[j]){
    //         ans = 1 + solve(text1,text2,i+1,j+1);
    //     }
    //     else{
    //         ans = max( solve(text1,text2,i+1,j) , solve(text1,text2,i,j+1) );
    //     }
    //     return ans;
    // }
    // int longestCommonSubsequence(string text1, string text2) {
        
    //     return solve(text1,text2,0,0);
    // }



    //MEMOIZATION
    // int solveDP(string &text1, string &text2,int i,int j,vector<vector<int>>& dp_arr){

    //     if( i>=text1.length() || j>=text2.length()) return 0;

    //     //step-3 check if ans already exist in dp_arr
    //     if(dp_arr[i][j]!=-1) return dp_arr[i][j];

    //     int ans = 0;
    //     if(text1[i]==text2[j]){
    //         ans = 1 + solveDP(text1,text2,i+1,j+1,dp_arr);
    //     }
    //     else{
    //         ans = max( solveDP(text1,text2,i+1,j,dp_arr) , solveDP(text1,text2,i,j+1,dp_arr) );
    //     }

    //     //step-2 store rec ans in dp_arr and return
    //     dp_arr[i][j]=ans;
    //     return dp_arr[i][j];
    // }
    // int longestCommonSubsequence(string text1, string text2) {

    //     int n = text1.length();
    //     int m = text2.length();
        
    //     //step-1 create dp array and pass
    //     vector<vector<int>> dp_arr(n+1,vector<int> (m+1,-1));
    //     return solveDP(text1,text2,0,0,dp_arr);
    // }



    //TABULATION
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.length();
    //     int m = text2.length();
    //     vector<vector<int>> dp(n+2,vector<int> (m+2,0));

    //     //i-> 0 to n
    //     //j-> 0 to m
    //     for(int N=n-1; N>=0; N--){
    //         for(int M=m; M>=0; M--){
    //             int ans = 0;
    //             if(text1[N]==text2[M]){
    //                 ans = 1 + dp[N+1][M+1];
    //             }
    //             else{
    //                 ans = max( dp[N+1][M] , dp[N][M+1] );
    //             }
    //             dp[N][M]=ans;
    //         }
    //     }
    //     return dp[0][0];
    // }



    //SPACE OPTIMIZATION
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // vector<vector<int>> dp(n+2,vector<int> (m+2,0));
        vector<int> next(m+2,0);
        vector<int> curr(m+2,0);

        //i-> 0 to n
        //j-> 0 to m
        for(int N=n-1; N>=0; N--){
            for(int M=m; M>=0; M--){
                int ans = 0;
                if(text1[N]==text2[M]){
                    ans = 1 + next[M+1];
                }
                else{
                    ans = max( next[M] , curr[M+1] );
                }
                curr[M]=ans;
            }
            //shifting
            next = curr;
        }
        return curr[0];
    }
};


