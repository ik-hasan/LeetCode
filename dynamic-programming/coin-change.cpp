class Solution {
public:

    //NORMAL RECURSION APPLY (without DP bhi logic shi h but TLE mar jaega)
    // int solve(vector<int>& coins,int amount){
    //     if(amount==0) return 0;
    //     int minmCoin = INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         if(coins[i]<=amount){
    //             int recAns = solve(coins,amount-coins[i]);
    //             if(recAns != INT_MAX){
    //                 int coinUsed = 1+recAns;
    //                 minmCoin = min(minmCoin,coinUsed);
    //             }
    //         }
    //     }
    //     return minmCoin;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     if(solve(coins,amount)==INT_MAX) return -1;
    //     return solve(coins,amount);
    // }



    //MEMOISATION / TOP-DOWN APPROACH
    // int solveDP(vector<int>& coins,int amount,vector<int>& dp_arr){
    //     if(amount==0) return 0;
    //     if(dp_arr[amount]!=-1){
    //         return dp_arr[amount];
    //     }
    //     int minmCoin = INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         if(coins[i]<=amount){
    //             int recAns = solveDP(coins,amount-coins[i],dp_arr);
    //             if(recAns != INT_MAX){
    //                 int coinUsed = 1+recAns;
    //                 minmCoin = min(minmCoin,coinUsed);
    //             }
    //         }
    //     }
    //     dp_arr[amount] = minmCoin;
    //     return dp_arr[amount];
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int> dp_arr(amount+1,-1);
    //     int ans = solveDP(coins,amount,dp_arr);
    //     if(ans==INT_MAX) return -1;
    //     return ans;
    // }



    //TABULATION / ITERATIVE / BOTTOM-UP APPROACH
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int> dp_arr(amount+1,-1);
    //     dp_arr[0]=0;

    //     for(int amt=1;amt<=amount;amt++){
    //         int minmCoin = INT_MAX;
    //         for(int i=0;i<coins.size();i++){
    //             if(coins[i]<=amt){
    //                 int recAns = dp_arr[amt-coins[i]];
    //                 if(recAns != INT_MAX){
    //                     int coinUsed = 1+recAns;
    //                     minmCoin = min(minmCoin,coinUsed);
    //                 }
    //             }
    //         }
    //         dp_arr[amt] = minmCoin;
    //     }
    //     return (dp_arr[amount] == INT_MAX) ? -1 : dp_arr[amount];
    // }




    // int count = INT_MAX;
    // void solve(vector<int>& coins, int amount, int currCount){
    //     if(amount==0) {
    //         count = min(currCount,count);
    //         return;
    //     }
    //     if(amount<0) {
    //         return;
    //     }

    //     for(int i=0;i<coins.size();i++){
    //         if(coins[i]<=amount){
    //             solve(coins,amount-coins[i],currCount+1);
    //         }
    //     }
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int currCount = 0;
    //     solve(coins,amount,currCount);
    //     if(count==INT_MAX) return -1;
    //     return count;
    // }





    int count = INT_MAX;

void solve(vector<int>& coins, int amount, int currCount, vector<int>& dp){ 
    if(amount==0){
        count = min(currCount,count);
        return;
    }

    if(amount<0){
        return;
    }

    if(dp[amount] <= currCount) return; 
    dp[amount] = currCount;             

    for(int i=0;i<coins.size();i++){
        if(coins[i]<=amount){
            solve(coins,amount-coins[i],currCount+1,dp);
        }
    }
}

int coinChange(vector<int>& coins, int amount) {
    int currCount = 0;
    vector<int> dp(amount+1, INT_MAX);

    solve(coins,amount,currCount,dp);  

    if(count==INT_MAX) return -1;
    return count;
}

};






