class Solution {
public:
    long long mod = 1000000007;

    //PURE REC SOLN
    // int solve(int n, int k, int target){
    //     if(n==1 && target <= k) return 1;
    //     if(n == 0 && target == 0) return 1;
    //     if(n == 0 || target < 0) return 0;

    //     int ans = 0;
    //     for(int i=1;i<=k;i++){
    //         ans = ans + solve(n-1,k,target-i);
    //     }
    //     return ans;
    // }
    // int numRollsToTarget(int n, int k, int target) {
    //     return solve(n,k,target)%mod;
    // }



    //MEMOIZATION
    // int solveMEM(int n, int k, int target,vector<vector<int>> &dp){
    //     // if(n==1 && target <= k) return 1;
    //     if(n == 0 && target == 0) return 1;
    //     if(n == 0 || target < 0) return 0;
    //     if(dp[n][target]!=-1) return dp[n][target];

    //     int ans = 0;
    //     for(int i=1;i<=k;i++){
    //         ans = ( ans + solveMEM(n-1,k,target-i,dp) )%mod;
    //     }
    //     dp[n][target]=ans;
    //     return dp[n][target];
    // }
    // int numRollsToTarget(int n, int k, int target) {
    //     vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
    //     return solveMEM(n,k,target,dp);
    // }



    //TABULATION
    // int numRollsToTarget(int n, int k, int target) {
    //     vector<vector<long long>> dp(n+1,vector<long long> (target+1,0));

    //     dp[0][0]=1;

    //     //n-> n to 0
    //     //target-> target to 0
    //     for(int N=1; N<=n; N++){
    //         for(int t=0; t<=target; t++){
    //             long long ans = 0;
    //             for(int i=1;i<=k;i++){
    //                 if(t-i>=0){
    //                     ans = ( ans + dp[N-1][t-i] )%mod;
    //                 }
    //             }
    //             dp[N][t]=ans;
    //         }
    //     }
    //     return dp[n][target];
    // }



    //SPACE OPTIMIZATION
    // int numRollsToTarget(int n, int k, int target) {
    //     // vector<vector<long long>> dp(n+1,vector<long long> (target+1,0));
    //     vector<int> prev(target+1,0);
    //     vector<int> curr(target+1,0);

    //     prev[0]=1;

    //     //n-> n to 0
    //     //target-> target to 0
    //     for(int N=1; N<=n; N++){
    //         for(int t=0; t<=target; t++){
    //             long long ans = 0;
    //             for(int i=1;i<=k;i++){
    //                 if(t-i>=0){
    //                     ans = ( ans + prev[t-i] )%mod;
    //                 }
    //             }
    //             curr[t]=ans;
    //         }
    //         // shifting yhi bhul rha hu bar bar
    //         prev=curr;
    //     }
    //     return curr[target];
    // }























    // int ans = 0;
    // void solve(int n,int k,int target){
    //     if(target == 0 && n==0) {
    //         ans++;
    //         return;
    //     }
    //     if(n==0){
    //         return;
    //     }
    //     for(int i=1;i<=k;i++){
    //         target = target - i;
    //         solve(n-1,k,target);
    //         target = target + i;
    //         //solve(n-1,k,target);
    //     }
    //     return;
    // }
    
    int solve(int n,int k,int target,vector<vector<int>> &dp){
        if(target < 0) return 0;  
        if(target==0 && n==0){
            return 1;
        }
        if(n==0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ans = 0;

        for(int i=1;i<=k;i++){
            target = target - i;
            ans = (ans + solve(n-1,k,target,dp))%mod;
            target = target + i;
        }
        dp[n][target]=ans;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp)%mod;
    }
};

























