class Solution {
public:

    //REC SOLN WITH TLE
    // int solve(int start, int n){
    //     if(start>=n) return 0;

    //     int minmAmountReqToWin = 0;
    //     int ans = INT_MAX;
    //     for(int i=start;i<n;i++){
    //         minmAmountReqToWin = i + max( solve(start,i-1), solve(i+1,n) );
    //         ans = min(ans,minmAmountReqToWin);
    //     }
    //     return ans;
    // }
    // int getMoneyAmount(int n) {
    //     return solve(1,n);
    // }


    //DP SOLN OF ABOVE CODE
    int solveDP(int start, int n,vector<vector<int>> &dp_arr){
        if(start>=n) return 0;


        //step-3
        if(dp_arr[start][n]!=-1){
            return dp_arr[start][n];
        }

        int minmAmountReqToWin = 0;
        int ans = INT_MAX;
        for(int i=start;i<n;i++){
            minmAmountReqToWin = i + max( solveDP(start,i-1,dp_arr), solveDP(i+1,n,dp_arr) );
            ans = min(ans,minmAmountReqToWin);
        }

        //step-2
        dp_arr[start][n]= ans;
        return dp_arr[start][n];
    }
    int getMoneyAmount(int n) {

        //STEP-1
        vector<vector<int>> dp_arr(n+1,vector<int>(n+1,-1));
        return solveDP(1,n,dp_arr);
    }
};