
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> &dp) {
        if (row == triangle.size() ) return 0;
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        int inc1 = triangle[row][col] + solve(triangle, row + 1, col,dp);
        int inc2 = triangle[row][col] + solve(triangle, row + 1, col + 1,dp);
        dp[row][col] = min(inc1, inc2);
        return dp[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int> (triangle.size(),INT_MAX));
        //triangle can also contaoni -1 thats why INT_MAX
        return solve(triangle, 0, 0,dp);
    }
};


