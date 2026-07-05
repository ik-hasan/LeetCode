class Solution {
public:
    // int solve(vector<int>& satisfaction,int index,int time){
    //     if(index>=satisfaction.size()) return 0;

    //     int inc = satisfaction[index] * time  +  solve(satisfaction,index+1,time+1);
    //     int exc = solve(satisfaction,index+1,time);

    //     return max(inc,exc);
    // }
    // int maxSatisfaction(vector<int>& satisfaction) {
    //     sort(satisfaction.begin(),satisfaction.end());
    //     return solve(satisfaction,0,1);
    // }



    //MEMOIZATION
    // int solve(vector<int>& satisfaction,int index,int time,vector<vector<int>> &dp){
    //     if(index>=satisfaction.size()) return 0;

    //     if(dp[index][time] != -1) return dp[index][time];

    //     int inc = satisfaction[index] * time  +  solve(satisfaction,index+1,time+1,dp);
    //     int exc = solve(satisfaction,index+1,time,dp);

    //     dp[index][time] = max(inc,exc);
    //     return dp[index][time];
    // }
    // int maxSatisfaction(vector<int>& satisfaction) {
    //     int n = satisfaction.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //     sort(satisfaction.begin(),satisfaction.end());
    //     return solve(satisfaction,0,1,dp);
    // }



    //TABULATION
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,0));
        sort(satisfaction.begin(),satisfaction.end());

        for(int index = n-1;index>=0;index--){
            for(int time = n;time>=1;time--){
                int inc = satisfaction[index] * time  +  dp[index+1][time+1];
                int exc = dp[index+1][time];

                dp[index][time] = max(inc,exc);
            }
        }
        return dp[0][1];
    }
};