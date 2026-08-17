// class Solution {
// public:
//     int solve(int i, vector<int>& coins, int amount) {
//         if (amount == 0) return 0;
//         if (i >= coins.size()) return INT_MAX;

//         int take = INT_MAX;
//         if (amount >= coins[i]) {
//             int x = solve(i, coins, amount - coins[i]);
//             if (x != INT_MAX) take = 1 + x;
//         }
//         int notTake = solve(i + 1, coins, amount);
//         return min(take, notTake);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int ans = solve(0, coins, amount);
//         return ans == INT_MAX ? -1 : ans;
//     }
// };



//memoization
// class Solution {
// public:
//     int solve(int i, vector<int>& coins, int amount,
//               vector<vector<int>>& dp) {

//         if (amount == 0)
//             return 0;

//         if (i >= coins.size())
//             return INT_MAX;

//         if (dp[i][amount] != -1)
//             return dp[i][amount];

//         int take = INT_MAX;

//         if (amount >= coins[i]) {
//             int x = solve(i, coins, amount - coins[i], dp);

//             if (x != INT_MAX)
//                 take = 1 + x;
//         }

//         int notTake = solve(i + 1, coins, amount, dp);

//         return dp[i][amount] = min(take, notTake);
//     }

//     int coinChange(vector<int>& coins, int amount) {

//         int n = coins.size();

//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

//         int ans = solve(0, coins, amount, dp);

//         return ans == INT_MAX ? -1 : ans;
//     }
// };


//tabulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, INT_MAX)
        );

        // amount = 0 => 0 coins
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int a = 1; a <= amount; a++) {

                int notTake = dp[i + 1][a];

                int take = INT_MAX;

                if (a >= coins[i]) {

                    int x = dp[i][a - coins[i]];

                    if (x != INT_MAX)
                        take = 1 + x;
                }

                dp[i][a] = min(take, notTake);
            }
        }

        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }
};