class Solution {
public:

    // bool solve(int i, int sum, vector<int>& nums, vector<vector<int>> &dp){
    //     if(i>=nums.size() || sum<0) return false;
    //     if(sum==0) return true;
    //     if(dp[i][sum] != 0) return dp[i][sum];

    //     dp[i][sum] = solve(i+1,sum,nums,dp) || solve(i+1,sum-nums[i],nums,dp);
    //     return dp[i][sum];
    // }
    // bool canPartition(vector<int>& nums) {
    //     int totalSum = accumulate(nums.begin(),nums.end(),0);
    //     if(totalSum%2) return false;
    //     int sum = totalSum/2;
    //     vector<vector<int>> dp(nums.size()+1,vector<int>((totalSum/2)+1,0));

    //     return solve(0,sum,nums,dp);
    // }



    bool solveTAB(vector<int>& nums, int target){
        int n= nums.size();
        vector< vector<bool> > dp(target+1,vector<bool>(n+1,0));
        for(int i=0;i<n+1;i++){
            dp[0][i]=1;
        }
        //target-> target to 0;
        //i -> 0 to n;
        for(int t = 1;t<=target;t++){
            for(int index = n-1;index>=0;index--){
                bool inc = false;
                if(t - nums[index] >= 0) {
                    inc = dp[t - nums[index]][index + 1];
                }
                bool exc = dp[t] [index+1];
                dp[t][index]=(inc || exc);
            }
        }
        return dp[target][0];
    } 
    bool canPartition(vector<int>& nums) {
        int checkSum=accumulate(nums.begin(),nums.end(),0);
        if(checkSum %2 != 0) return false;
        int n= nums.size();
        int target = checkSum >> 1;

        return solveTAB(nums,target);
    }
};

