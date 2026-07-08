// class Solution {
// public:

//     int solve(int i,int j, vector<vector<int>>& grid){
//         if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
//         if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;

//         int right = solve(i, j+1, grid);
//         int down  = solve(i+1, j, grid);

//         if(right != INT_MAX) right += grid[i][j];
//         if(down != INT_MAX) down += grid[i][j];

//         return min(right, down);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         return solve(0,0,grid);
//     }
// };


class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == grid.size()-1 && j == grid[0].size()-1)
            return grid[i][j];

        if(i >= grid.size() || j >= grid[0].size())
            return INT_MAX;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j+1, grid, dp);
        int down  = solve(i+1, j, grid, dp);

        if(right != INT_MAX) right += grid[i][j];
        if(down != INT_MAX)  down += grid[i][j];

        return dp[i][j] = min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, grid, dp);
    }
};