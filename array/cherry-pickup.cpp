// class Solution {
// public:
//     //most important observation => r1+c1=r2+c2 it will always hold,
//     // we are solving this problem by starting both person from (0,0)

//     int solve(int r1, int c1, int r2, vector<vector<int>>& grid){
//         int n = grid.size();
//         int c2 = r1+c1-r2;
//         if(r1>=n || c1>=n || r2>=n || c2>=n) return -1e9;
//         if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e9;
//         if (r1 == n - 1 && c1 == n - 1)
//             return grid[r1][c1];

//         int cherry = 0;
//         if(r1==r2 && c1==c2) cherry = grid[r1][c1];
//         else cherry = grid[r1][c1] + grid[r2][c2];

//         int ans = -1e9;
//         ans = max({
//             solve(r1+1,c1,r2+1,grid),//down down
//             solve(r1,c1+1,r2,grid),//right right
//             solve(r1+1,c1,r2,grid),//down right
//             solve(r1,c1+1,r2+1,grid)//right down
//         });

//         return ans+cherry;
//     }
//     int cherryPickup(vector<vector<int>>& grid) {
//         return max(0,solve(0,0,0,grid));
//     }
// };

class Solution {
public:

    int dp[51][51][51];

    // Most important observation:
    // r1 + c1 = r2 + c2
    // We solve the problem by considering both persons starting from (0,0)

    int solve(int r1, int c1, int r2, vector<vector<int>>& grid){

        int n = grid.size();
        int c2 = r1 + c1 - r2;

        if(r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 ||
           r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return -1e9;

        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherry;

        if(r1 == r2 && c1 == c2)
            cherry = grid[r1][c1];
        else
            cherry = grid[r1][c1] + grid[r2][c2];

        int ans = -1e9;

        ans = max({
            solve(r1+1, c1,   r2+1, grid), // Down Down
            solve(r1,   c1+1, r2,   grid), // Right Right
            solve(r1+1, c1,   r2,   grid), // Down Right
            solve(r1,   c1+1, r2+1, grid)  // Right Down
        });

        return dp[r1][c1][r2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        memset(dp, -1, sizeof(dp));

        return max(0, solve(0,0,0,grid));
    }
};