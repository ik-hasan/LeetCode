class Solution {
public:

    //BRUTE FORCE ISME DP NHI LGA SKTA
    // int solve(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;

    //     int ans = 0;

    //     for (int i = 0; i < nums.size(); i++) {

    //         int left = (i - 1 >= 0) ? nums[i - 1] : 1;
    //         int right = (i + 1 < nums.size()) ? nums[i + 1] : 1;

    //         int coins = left * nums[i] * right;

    //         int temp = nums[i]; //store for backtracking
    //         nums.erase(nums.begin() + i);   // REAL BURST

    //         coins += solve(nums);

    //         nums.insert(nums.begin() + i, temp); // BACKTRACK

    //         ans = max(ans, coins);
    //     }

    //     return ans;
    // }

    // int maxCoins(vector<int>& nums) {
    //     return solve(nums);
    // }




    //REC SOLN
    // int solve(vector<int>& nums,int start, int end){
    //     if(start>end) return 0;
    //     int coins = INT_MIN;
    //     for(int i=start;i<=end;i++){
    //         coins = max( coins , nums[start-1] * nums[i] * nums[end+1] + solve(nums,start,i-1) + solve(nums,i+1,end) );
    //         //yha pr hm ulta solve kr rhe h, mtlb ye soch kr ki ek hi balloon bcha h fodne ke liye.
    //     }
    //     return coins;
    // }
    // int maxCoins(vector<int>& nums) {
    //     nums.insert(nums.begin(),1);
    //     nums.insert(nums.end(),1);
    //     return solve(nums,1,nums.size()-2);
    // }



    //MEMOIZATION
    // int solve(vector<int>& nums,int start, int end, vector<vector<int>> &dp){
    //     if(start>end) return 0;
    //     if(dp[start][end] != -1 ) return dp[start][end];
    //     int coins = INT_MIN;
    //     for(int i=start;i<=end;i++){
    //         coins = max( coins , nums[start-1] * nums[i] * nums[end+1] 
    //                                         + solve(nums,start,i-1,dp) 
    //                                         + solve(nums,i+1,end,dp) );
    //     }
    //     dp[start][end]=coins;
    //     return dp[start][end];
    // }
    // int maxCoins(vector<int>& nums) {
    //     nums.insert(nums.begin(),1);
    //     nums.insert(nums.end(),1);
    //     vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    //     return solve(nums,1,nums.size()-2,dp);
    // }



    //BOTTOM UP
    int solveBU(vector<int>& nums) {
        int n = nums.size() - 2;   // assuming nums already has 1 added at both ends

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        for (int start = n; start >= 1; start--) {
            for (int end = start; end <= n; end++) {

                int coins = 0;

                for (int i = start; i <= end; i++) {
                    coins = max(
                        coins,
                        nums[start - 1] * nums[i] * nums[end + 1]
                        + dp[start][i - 1]
                        + dp[i + 1][end]
                    );
                }

                dp[start][end] = coins;
            }
        }

        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        return solveBU(nums);
    }
};
