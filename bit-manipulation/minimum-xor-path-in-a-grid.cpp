class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int xr,vector<vector<vector<int>>> &dp){
        if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;

        xr = xr ^ grid[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1) return xr;

        if(dp[i][j][xr]!=-1) return dp[i][j][xr];

        int ans = INT_MAX;

        int right = solve(grid,i,j+1,xr,dp);
        int down = solve(grid,i+1,j,xr,dp);

        ans = min(ans,right);
        ans = min(ans,down);
        
        dp[i][j][xr] = ans;
        return dp[i][j][xr];
    }
    
    int minCost(vector<vector<int>>& grid) {
    
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(1024,-1)));
        return solve(grid,0,0,0,dp);
    }
};
