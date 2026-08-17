// class Solution {
// public:
//     int solve(int i, vector<int>& coins, int amount) {

//         // amount successfully ban gaya
//         if (amount == 0)
//             return 1;
//         // coins khatam ho gaye
//         if (i >= coins.size())
//             return 0;

//         int take = 0;
//         if (amount >= coins[i]) {
//             take = solve(i, coins, amount - coins[i]);
//         }
//         int notTake = solve(i + 1, coins, amount);
//         return take + notTake;
//     }

//     int change(int amount,vector<int>& coins) {
//         return solve(0, coins, amount);
//     }
// };


//mem
// class Solution {
// public:
//     int solve(int i, vector<int>& coins, int amount,
//               vector<vector<int>>& dp) {

//         if (amount == 0)
//             return 1;

//         if (i >= coins.size())
//             return 0;

//         if (dp[i][amount] != -1)
//             return dp[i][amount];

//         int take = 0;

//         if (amount >= coins[i]) {
//             take = solve(i, coins, amount - coins[i], dp);
//         }

//         int notTake = solve(i + 1, coins, amount, dp);

//         return dp[i][amount] = take + notTake;
//     }

//     int change(int amount, vector<int>& coins) {

//         int n = coins.size();

//         vector<vector<int>> dp(
//             n, vector<int>(amount + 1, -1)
//         );

//         return solve(0, coins, amount, dp);
//     }
// };


//tab
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, 0)
        );

        // amount = 0 banane ka exactly 1 way:
        // kuch bhi nahi lena
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int a = 1; a <= amount; a++) {

                int take = 0;

                if (a >= coins[i]) {
                    take = dp[i][a - coins[i]];
                }

                int notTake = dp[i + 1][a];

                dp[i][a] = take + notTake;
            }
        }

        return dp[0][amount];
    }
};