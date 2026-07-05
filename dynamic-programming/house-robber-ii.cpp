//REC SOLN BUT WITH TLE
// class Solution {
// public:
//     int solve(vector<int>& nums,int index,int size){
//         if(index>size) return 0;

//         int inc = nums[index] + solve(nums,index+2,size);
//         int exc = solve(nums,index+1,size);

//         return max(inc,exc);
//     }
//     int rob(vector<int>& nums) {
//         if(nums.size()==1) return nums[0];
//         int inc = solve(nums,0,nums.size()-2);//if we rob first home then left lastone
//         int exc = solve(nums,1,nums.size()-1);//if we left first home then rob lastone
//         return max(inc,exc);
//     }
// };


//DP SOLN OF ABOVE CODE TO FIGHT WITH TLE
// class Solution {
// public:
//     int solve(vector<int>& nums,int index,int size,vector<int>& dp_arr){
//         if(index>size) return 0;

//         if(dp_arr[index] != -1){
//             return dp_arr[index];
//         }

//         int inc = nums[index] + solve(nums,index+2,size,dp_arr);
//         int exc = solve(nums,index+1,size,dp_arr);

//         dp_arr[index] = max(inc,exc);
//         return dp_arr[index];
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return nums[0];

//         vector<int> dp_arr1(n, -1);
//         vector<int> dp_arr2(n, -1);
        
//         int inc = solve(nums,0,nums.size()-2,dp_arr1);//if we rob first home then left lastone
//         int exc = solve(nums,1,nums.size()-1,dp_arr2);//if we left first home then rob lastone
//         return max(inc,exc);
//     }
// };


























class Solution {
public:
    int solve(vector<int>& nums,int index,int size,vector<vector<int>> &dp){
        if(index > size) return 0;
        if(dp[index][size]!=-1) return dp[index][size];
     
        int inc = nums[index] + solve(nums,index+2,size,dp);
        int exc = solve(nums,index+1,size,dp);
     
        dp[index][size] = max(inc,exc);
        return dp[index][size];
    }  
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<vector<int>> dp1(nums.size(),vector<int> (nums.size(),-1));
        vector<vector<int>> dp2(nums.size(),vector<int> (nums.size(),-1));
        int inc = solve(nums,0,nums.size()-2,dp1);
        int exc = solve(nums,1,nums.size()-1,dp2);
        return max(inc,exc);
    }
};
























