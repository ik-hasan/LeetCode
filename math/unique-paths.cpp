class Solution {
public:

    int solve(int i,int j, int m,int n){
        if(i==m-1 && j==n-1) return 1;
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        
        int down = solve(i+1,j,m,n);
        int right = solve(i,j+1,m,n);

        return down + right;
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};