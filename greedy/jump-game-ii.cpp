class Solution {
public:
    //hmara logic shi h bs DP lga kr Optimize krna h fir TLE nhi marega
    // int solve(vector<int> nums,int index,int result){
    //     if(index == nums.size()-1) return result;
    //     if(index >= nums.size()) return INT_MAX;

    //     int ans = INT_MAX;
    //     for(int i=1;i<=nums[index];i++){
    //         ans = min( ans,solve(nums,index+i,result+1) );
    //     }
    //     return ans;
    // }
    // int jump(vector<int>& nums) {
    //     int index = 0,result = 0;
    //     return solve(nums,index,result);
    // }


    //DP SOLN OF ABOVE CODE
    // int solvedp(vector<int> &nums,int index,int result,vector<vector<int>> &dp_arr){
    //     if(index == nums.size()-1) return result;
    //     if(index >= nums.size()) return INT_MAX;

    //     if(dp_arr[index][result] != -1){
    //         return dp_arr[index][result];
    //     }

    //     int ans = INT_MAX;
    //     for(int i=1;i<=nums[index];i++){
    //         ans = min( ans,solvedp(nums,index+i,result+1,dp_arr) );
    //     }

    //     dp_arr[index][result]=ans;
    //     return dp_arr[index][result];
    // }
    // int jump(vector<int>& nums) {
    //     int index = 0,result = 0;
    //     int n = nums.size();

    //     //STEP-1 CREATE AND PASS DP_ARR
    //     vector<vector<int>> dp_arr(n+1,vector<int>(n+1,-1));
    //     // vector<int> dp_arr(n+1,-1);
    //     return solvedp(nums,index,result,dp_arr);
    // }
    












    int solve(vector<int>& nums, int index,vector<int> &dp){
        if(index >= nums.size()) return INT_MAX;
        if(index==nums.size()-1){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        int ans = INT_MAX;
        for(int i=1;i<=nums[index];i++){
            int temp = solve(nums,index+i,dp);
            if(temp!=INT_MAX) ans = min( ans, 1 + temp);
        }
        dp[index]=ans;
        return dp[index];
    }
    int jump(vector<int>& nums){
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }


};