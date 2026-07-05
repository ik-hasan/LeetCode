
//BASIC WALA REC WITH TLE
// class Solution {
// public:
//     int solve(vector<int>& nums,int index){
//         if(index>=nums.size()) return 0;

//         int inc = nums[index]+solve(nums,index+2);
//         int exc = solve(nums,index+1);

//         return max(inc,exc);
//     }
//     int rob(vector<int>& nums) {
//         return solve(nums,0);
//     }
// };






//APPROACH 1 - TOP DOWN APPROACH OF DP
class Solution {
public:
    int solveByDP(vector<int> nums, int i,vector<int>& dp_arr){
        if(i>=nums.size()) return 0;
        if(dp_arr[i]!=-1){  //step (3) check solution is already exist in dp array or not
            return dp_arr[i];
        }

        //apply include exclude technique of Recursion
        int include = nums[i]+solveByDP(nums,i+2,dp_arr);
        int exclude = 0 + solveByDP(nums,i+1,dp_arr);
        dp_arr[i]=max(include , exclude);//step (2) store value of rec call in dp array

        return dp_arr[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp_arr(n+1,-1);//step (1) create dp array
        return solveByDP(nums,0,dp_arr);
    }
};





//APPROACH 2 - BOTTOM UP APPROACH OF DP
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp_arr(n+2,-1);//step (1) create dp array
//         dp_arr[n]=0;//step (2) 
//         dp_arr[n+1]=0;

//         for(int i=n-1;i>=0;i--){//step (3)
//             int include = nums[i]+dp_arr[i+2];
//             int exclude = 0 + dp_arr[i+1];
//             dp_arr[i]=max(include , exclude);
//         }

//         return dp_arr[0];
//     }
// };




// APPROACH 3- SPACE OPTIMIZATION
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         int next1=0;
//         int next2=0;

//         for(int i=n-1;i>=0;i--){//step (3)
//             int include = nums[i]+next2;
//             int exclude = 0 + next1;
//             int curr=max(include , exclude);

//             next2=next1;
//             next1=curr;
//         }
//         return next1;
//     }
// };
