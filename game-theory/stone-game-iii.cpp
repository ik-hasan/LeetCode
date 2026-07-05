class Solution {
public:
    // int solve(vector<int>& stoneValue, int index, bool alice) {
    //     if(index >= stoneValue.size()) return 0;

    //     int ans = alice ? INT_MIN : INT_MAX;

    //     int total = 0;
    //     for(int i = 0; i < 3; i++) {
    //         if(index + i >= stoneValue.size()) break;

    //         total += stoneValue[index + i];
    //         if(alice) {
    //             ans = max(ans, total + solve(stoneValue, index + i + 1, !alice));
    //         } else {
    //             ans = min(ans, -total + solve(stoneValue, index + i + 1, !alice));//alice ke score me bob ka score minus kr rhe h & at the end ans ki value agr +ve rhi mtlb alice win, -Ve rhi mtlb bob win, equal rhi mtlb game tie.
    //         }
    //     }
    //     return ans;
    // }

    // string stoneGameIII(vector<int>& stoneValue) {
    //     int ans = solve(stoneValue, 0, true);

    //     if(ans > 0) return "Alice";
    //     if(ans < 0) return "Bob";
    //     return "Tie";
    // }



    //MEMOIZATION
    // int solve(vector<int>& stoneValue, int index, bool alice, vector<vector<int>>& dp) {
    //     if(index >= stoneValue.size()) return 0;

    //     if(dp[index][alice] != -1 ) return dp[index][alice];

    //     int ans = alice ? INT_MIN : INT_MAX;

    //     int total = 0;
    //     for(int i = 0; i < 3; i++) {
    //         if(index + i >= stoneValue.size()) break;

    //         total += stoneValue[index + i];
    //         if(alice) {
    //             ans = max(ans, total + solve(stoneValue, index + i + 1, !alice,dp));
    //         } else {
    //             ans = min(ans, -total + solve(stoneValue, index + i + 1, !alice,dp));
    //         }
    //     }
    //     dp[index][alice]=ans;
    //     return dp[index][alice];
    // }

    // string stoneGameIII(vector<int>& stoneValue) {

    //     int n = stoneValue.size();
    //     vector<vector<int>> dp(n+1,vector<int>(2,-1));
    //     int ans = solve(stoneValue, 0, true,dp);

    //     if(ans > 0) return "Alice";
    //     if(ans < 0) return "Bob";
    //     return "Tie";
    // }



    //TABULATION
    int solve(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int index = stoneValue.size()-1;index >=0;index--){
            for(int alice=0;alice<=1;alice++){

                int ans = alice ? INT_MIN : INT_MAX;
                int total = 0;
                for(int i = 0; i < 3; i++) {
                    if(index + i >= stoneValue.size()) break;

                    total += stoneValue[index + i];
                    if(alice) {
                        ans = max(ans, total + dp[index + i + 1] [!alice]);
                    } else {
                        ans = min(ans, -total + dp[index + i + 1][!alice]);
                    }
                }
                dp[index][alice]=ans;
            }
        }
        return dp[0][1];
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int ans = solve(stoneValue);

        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
};
