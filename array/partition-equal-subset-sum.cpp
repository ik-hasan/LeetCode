class Solution {
public:

    //REC SOLN
    // bool solve(vector<int>& nums, int index,int sum){
    //     if(sum==0) return true;
    //     if(index >= nums.size() ||sum<0) return false;
    //     bool inc = solve(nums,index+1,sum-nums[index]);
    //     bool exc = solve(nums,index+1,sum);

    //     return (inc || exc);
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum =0;
    //     for(int i=0;i<nums.size();i++){
    //         sum+=nums[i];
    //     }
    //     if(sum%2!=0) return false;

    //     return solve(nums,0,sum/2);
    // }



    //REC SOLN
    // bool solve(vector<int>& nums,int target,int i){
    //     if(target==0) return true;
    //     if(target < 0 || i>=nums.size()) return false;

    //     bool inc = solve(nums,target-nums[i],i+1);
    //     bool exc = solve(nums,target,i+1);

    //     return (inc || exc );
    // }
    // bool canPartition(vector<int>& nums) {
    //     int checkSum=accumulate(nums.begin(),nums.end(),0);//initial value is 0 & add all elem of nums in it from begin to end
    //     if(checkSum %2 != 0) return false;
    //     int n= nums.size();
    //     int target = checkSum >> 1;//right shift(menas divided by 2)
    //     return solve(nums,target,0);
    // }



    //MEMOIZATION
    // bool solveDP(vector<int>& nums,int target,int i,vector< vector<int> > &dp_arr){
    //     if(target==0) return true;
    //     if(target < 0 || i>=nums.size()) return false;

    //     if(dp_arr[target][i] != -1){
    //         return dp_arr[target][i];
    //     }

    //     bool inc = solveDP(nums,target-nums[i],i+1,dp_arr);
    //     bool exc = solveDP(nums,target,i+1,dp_arr);

    //     dp_arr[target][i]=(inc || exc);
    //     return dp_arr[target][i];
    // }//2d dp
    // bool canPartition(vector<int>& nums) {
    //     int checkSum=accumulate(nums.begin(),nums.end(),0);
    //     if(checkSum %2 != 0) return false;
    //     int n= nums.size();
    //     int target = checkSum >> 1;

    //     vector< vector<int> > dp_arr(target+1,vector<int>(n+1,-1));
    //     return solveDP(nums,target,0,dp_arr);
    // }



    //TABULATION
    // bool solveTAB(vector<int>& nums, int target){
    //     int n= nums.size();
    //     vector< vector<bool> > dp(target+1,vector<bool>(n+1,0));
    //     for(int i=0;i<n+1;i++){
    //         dp[0][i]=1;
    //     }
    //     //target-> target to 0;
    //     //i -> 0 to n;
    //     for(int t = 1;t<=target;t++){
    //         for(int index = n-1;index>=0;index--){
    //             bool inc = false;
    //             if(t - nums[index] >= 0) {
    //                 inc = dp[t - nums[index]][index + 1];
    //             }
    //             bool exc = dp[t] [index+1];
    //             dp[t][index]=(inc || exc);
    //         }
    //     }
    //     return dp[target][0];
    // } 
    // bool canPartition(vector<int>& nums) {
    //     int checkSum=accumulate(nums.begin(),nums.end(),0);
    //     if(checkSum %2 != 0) return false;
    //     int n= nums.size();
    //     int target = checkSum >> 1;

    //     return solveTAB(nums,target);
    // }



    //SPACE OPTIMIZATION
    // bool solveTABSO(vector<int>& nums, int target){
    //     int n= nums.size();
    //     vector<bool> curr(target+1,0);
    //     vector<bool> next(target+1,0);
    //     for(int i=0;i<n+1;i++){
    //         next[0]=1;
    //     }

    //     for(int index = n-1;index>=0;index--){
    //         for(int t = 1;t<=target;t++){
    //             bool inc = false;
    //             if(t - nums[index] >= 0) {
    //                 inc = next[t - nums[index]];
    //             }
    //             bool exc = next[t];
    //             curr[t]=(inc || exc);
    //         }
    //         //shifting yhi bhulunga bar bar
    //         next=curr;
    //     }
    //     return next[target];
    // } 
    // bool canPartition(vector<int>& nums) {
    //     int checkSum=accumulate(nums.begin(),nums.end(),0);
    //     if(checkSum %2 != 0) return false;
    //     int n= nums.size();
    //     int target = checkSum >> 1;

    //     return solveTABSO(nums,target);
    // }



    //MORE OPTIMISED VERSION OF SPACE OPTIMIZATION
    bool solveTABSO2(vector<int>& nums, int target){
        int n= nums.size();
        vector<bool> curr(target+1,0);
        // vector<bool> next(target+1,0);
        for(int i=0;i<n+1;i++){
            curr[0]=true;
        }

        for(int index = n-1;index>=0;index--){
            for(int t = target; t>=1; t--){
                bool inc = false;
                if(t - nums[index] >= 0) {
                    inc = curr[t - nums[index]];
                }
                bool exc = curr[t];
                curr[t]=(inc || exc);
            }
        }
        return curr[target];
    } 
    bool canPartition(vector<int>& nums) {
        int checkSum=accumulate(nums.begin(),nums.end(),0);
        if(checkSum %2 != 0) return false;
        int n= nums.size();
        int target = checkSum >> 1;

        return solveTABSO2(nums,target);
    }
};