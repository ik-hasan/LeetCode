class Solution {
public:

    long long solve(int i,int j, vector<vector<int>>& grid){
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;

        long long right = grid[i][j] + solve(i,j+1,grid);
        long long down = grid[i][j] + solve(i+1,j,grid);

        return min(right, down);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        return solve(0,0,grid);
    }
};