

//DP Top Down approach
// class Solution {
// public:
//     int solve(int n,vector<int>& dp_arr){
//         if(n==0) return 0;
//         if(n==1) return 1;
//         if(dp_arr[n] != -1){
//             return dp_arr[n];
//         }
//         dp_arr[n]=solve(n-1,dp_arr)+solve(n-2,dp_arr);
//         return dp_arr[n];
//     }
//     int fib(int n) {
//         vector<int> ans(n+1,-1);
//         return solve(n,ans);
//     }
// };



//DP Bottom Top approach
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        if(n==0) return 0;
        // if(n==1) return 1;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};