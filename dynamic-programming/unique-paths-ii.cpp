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



//MEMOIZATON
// class Solution {
// public:

//     int solve(int i, int j, vector<vector<int>>& obs, vector<vector<int>>& dp){
//         if(i == obs.size()-1 && j == obs[0].size()-1) return 1;
//         if(i >= obs.size() || j >= obs[0].size()) return 0;
//         if(obs[i][j] == 1) return 0;
//         if(dp[i][j] != -1) return dp[i][j];

//         int right = solve(i, j+1, obs, dp);
//         int down = solve(i+1, j, obs, dp);
//         return dp[i][j] = right + down;
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return solve(0, 0, obstacleGrid, dp);
//     }
// };




//TABULATION
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        //base case thing
        dp[n-1][m-1] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){

                if( (i == n-1 && j == m-1) || obstacleGrid[i][j] == 1) continue;
                int right = 0, down = 0;

                if(j + 1 < m) right = dp[i][j+1];

                if(i + 1 < n) down = dp[i+1][j];

                dp[i][j] = right + down;
            }
        }

        return dp[0][0];
    }
};