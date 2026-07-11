class Solution {
public:

    int solve(int row, int col1, int col2, vector<vector<int>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();
        if(row>=n || row<0 || col1>=m || col1<0 || col2>=m || col2<0) return -1e9;

        int totalCherry = 0;
        if(col1==col2) totalCherry = grid[row][col1];
        else totalCherry = grid[row][col1] + grid[row][col2];

        int ans = 0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                ans = max(ans,solve(row+1,col1+i,col2+j,grid));
            }
        }
        return totalCherry+ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        return solve(0,0,grid[0].size()-1,grid);
    }
};