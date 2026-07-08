// class Solution {
// public:

//     int solve(int i, int j, vector<vector<int>>& obs){
//         if(i==obs.size()-1 && j==obs[0].size()-1) return 1;
//         if(i>=obs.size() || j>=obs[0].size()) return 0;
//         if(obs[i][j]==1) return 0;

//         int right = solve(i,j+1,obs);
//         int down = solve(i+1,j,obs);
//         return right + down;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         if(obstacleGrid[n-1][m-1]==1) return  0;
//         return solve(0,0,obstacleGrid);

//     }
// };

class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& obs, vector<vector<int>>& dp){
        if(i == obs.size()-1 && j == obs[0].size()-1) return 1;
        if(i >= obs.size() || j >= obs[0].size()) return 0;
        if(obs[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j+1, obs, dp);
        int down = solve(i+1, j, obs, dp);
        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, obstacleGrid, dp);
    }
};