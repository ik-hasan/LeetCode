class Solution {
public:
    //BASIC REC SOLN WITH TLE
    // int solve(int n){
    //     if(n==0) return 1;
    //     if(n<0) return 0;

    //     int i = 1;
    //     int end = sqrt(n);
    //     int ans = INT_MAX;
    //     while(i <= end){
    //         int count = 1 + solve(n-(i*i));
    //         if(count < ans){
    //             ans = count;
    //         }
    //         i++;
    //     }
    //     return ans;  
    // }
    // int numSquares(int n) {
    //     return solve(n)-1;
    // }


    //DP SOLN OF ABOVE CODE
    // int solveDP(int n, vector<int> &dp_arr){
    //     if(n==0) return 1;
    //     if(n<0) return 0;

    //     //step-3 
    //     if(dp_arr[n] != -1){
    //         return dp_arr[n];
    //     }

    //     int i = 1;
    //     int end = sqrt(n);
    //     int ans = INT_MAX;
    //     while(i <= end){
    //         int count = 1 + solveDP(n-(i*i), dp_arr);
    //         if(count < ans){
    //             ans = count;
    //         }
    //         i++;
    //     }
    //     //STEP-2
    //     dp_arr[n]=ans;
    //     return dp_arr[n];  
    // }
    // int numSquares(int n) {

    //     //STEP-1
    //     vector<int> dp_arr(n+1,-1);
    //     return solveDP(n,dp_arr)-1;
    // }






































    // int solve(int n, int k, int currAns, vector<vector<int>> &dp){
    //     if(n == 0) {
    //         return currAns;
    //     }
    //     if(n<0) return INT_MAX;
    //     if(dp[n][currAns]!=-1) return dp[n][currAns];
    //     int ans = INT_MAX;

    //     for(int i=1;i<=sqrt(k);i++){
    //         n=n-i*i;
    //         ans = min(ans,solve(n,k,currAns+1,dp));
    //         n=n+i*i;
    //     }
    //     dp[n][currAns]=ans;
    //     return dp[n][currAns];
    // }
    // int numSquares(int n) {
    //     if(n==1) return 1;
    //     int currAns = 0;
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //     int k = n;
    //     return solve(n,k,currAns,dp);
    // }

    int solve(int n, vector<int> &dp){
        if(n == 0) {
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;

        for(int i=1;i * i <= n;i++){
            ans = min(ans,1+solve(n-i*i,dp));
        }
        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }





};