class Solution {
public:

    // int ans = INT_MAX;
    // void solve(vector<vector<int>>& mat, int target, int row, int col,int currAns){
    //     if(row>=mat.size()){
    //         int a = abs(currAns-target);
    //         ans = min(ans,a);
    //         return;
    //     }

    //     for(int i=0;i<mat[0].size();i++){
    //         currAns = currAns + mat[row][i];
    //         solve(mat,target,row+1,i,currAns);
    //         currAns = currAns - mat[row][i];
    //     }
    //     return;
    // }

    int solve(vector<vector<int>>& mat, int target, int row, int currAns, vector<vector<int>> &dp){
        if(row>=mat.size()){
            return abs(currAns-target);
        }
        if(dp[row][currAns]!=-1) return dp[row][currAns];
        int ans = INT_MAX;
        for(int i=0;i<mat[0].size();i++){
            ans = min(ans,solve(mat,target,row+1,currAns+mat[row][i],dp));
        }
        dp[row][currAns] = ans;
        return dp[row][currAns];
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<vector<int>> dp(mat.size(),vector<int> (4900,-1));
        return solve(mat,target,0,0,dp);
    }
};